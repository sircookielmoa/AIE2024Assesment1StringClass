
#include "String.h"

#include <cctype>
#include <cstring>
#include <iostream>
#include <windows.h>

//I cast fireball on your class, level 9, it does 8d6. (Zac's comment)

String::String()
	: str(nullptr)
{
	str = new char[1] {'\0'};
}

String::String(const char* _str)
	: str(nullptr)
{
	//1. Figure out how much text _str is pointing at
	std::size_t _strLen = std::strlen(_str) + 1;

	//2. Make str point at an array big enough to fit the text in _str
	str = new char[_strLen + 1];
	//3. Copy the text from _str to str.
	std::strncpy(str, _str, _strLen);
}


String::String(const String& _other)					//copy constructor
	: String(_other.str)
{

}

String::~String()
{
	delete[] str;
}


size_t String::Length() const							//Returns the length of the string
{
	return std::strlen(str);
}

char& String::CharacterAt(size_t _index)				//Returns the character at a requested location within an array
{														//eg. "Hello world" CharacterAt 3 = 'l'
	if (_index > Length())
	{
		_index = Length();
	}

	return str[_index];
}

const char& String::CharacterAt(size_t _index) const	 //Character at location but constant?
{
	if (_index > Length())
	{
		_index = Length();
	}

	return str[_index];

}

const char* String::CStr() const						//Prints the value of string (std::cout << "string"; )
{
	return str;
}

bool String::EqualTo(const String& _other) const		//Determines if one string input is identical to another string.
{														//First checks the length of the two strings if they match, and if so,
	if (strlen(_other.CStr()) != strlen(str))			//checks if all the characters in the string array match, prints true if true.
	{
		return false;
	}
	
	for (int i = 0; i < Length(); ++i)
	{
		if (std::strcmp (_other.CStr(), str) == 0)
		{
			return true;
		}

	}
	return false;
}

String& String::Append(const String& suffix)			//Appends (text B) onto the end of (text A).
{														//Checks the length of (text A) and (text B), makes a new array combining the 2 lengths	
	int newLength = (Length() + suffix.Length());		//into a new string with both strings in one array.
	char* tempString = new char [newLength + 1];
	std::strncpy(tempString, str, Length() + 1);
	//*(tempString + Length()) = 0;
	std::strncat(tempString, suffix.str, suffix.Length());
	String::~String();
	str = tempString;
	return *this;
}

String& String::Prepend(const String& prefix)			//Prepends (text B) onto the front of (text A)/
{														//Does the same thing as Append but instead places (text B) before (text A).
	int newLength = (Length() + prefix.Length());
	char* tempString = new char[newLength + 1];
	std::strncpy(tempString, prefix.str, prefix.Length() + 1);
	//*(tempString + Length()) = 0;
	std::strncat(tempString, str, Length());
	String::~String();
	str = tempString;
	return *this;
}

String& String::ToLower()								//Changes all characters in a string to lowercase using the std::tolower function
{														//in the cctype header.
	for(int i = 0; i < strlen(str); ++i)	
	{
		str[i] = std::tolower(str[i]);
		
	}

	return *this;
}

String& String::ToUpper()								//Changes all characters in a string to uppercase using the std::toupper function
{														//in the cctype header.
	for (int i = 0; i < strlen(str); ++i)
	{
		str[i] = std::toupper(str[i]);
	}

	return* this;
}

size_t String::Find(const String& _str)	const			//Finds first index in the string
{
	return Find(0, _str);
}

size_t String::Find(size_t _startIndex, const String& _str) const
{
	//1. Use strstr to located_str with this string
	const char* foundPos = std:: strstr(this->str + _startIndex, _str.str);
	//1a. If nullptr, _str not found
	if (foundPos == nullptr)
	{
		return std::size_t(-1);
	}
	//2.

	return size_t(foundPos - this->str);
}

const String& String::WriteToConsole() const			//Prints a string to the console.
{
	std::cout << str << std::endl;
	return *this;
}

String& String::ReadFromConsole()						//Reads a string of user input from the console and saves it as str.
{												
	std::istream::sentry fetcher(std::cin);

	if (!fetcher)
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		return *this;
	}

	std::streamsize bufferedText = std::cin.rdbuf()->in_avail();
	char* newStr = new char[bufferedText];

	std::cin.rdbuf()->sgetn(newStr, bufferedText);
	newStr[bufferedText - 1] = '\0';

	delete[] this->str;
	this->str = newStr;

	return *this;
		
}

//JARED'S WORK --------------------------------------------------------------------------------------
//"NOT NECESSARY FOR ASSESMENT, JUST PUT IT IN FOR USE IN TEXT ADVENTURE GAME" -JARED

size_t String::CountMatches(size_t _startIndex, const String& _find) const
{
	size_t findLength = _find.Length();
	size_t count = 0;
	//This loop goes through each occurrence of the string _find and counts them.
	for (const char* next = std::strstr(this->str + _startIndex, _find.str);
		next != nullptr;
		next = std::strstr(next, _find.str))
	{
		++count;
		next += findLength;
	}
	return count;
}

String& String::Replace(const String& _find, const String& _replace)
{
	//If _find doesn't occur anywhere in the string, of if _find is empty,
	// nothing has to change.
	const char* nextOccurrence = std::strstr(this->str, _find.str);
	if (nextOccurrence == nullptr || _find.Length() == 0)
	{
		return *this;
	}
	size_t findLength = _find.Length();
	size_t replaceLength = _replace.Length();
	//Finds and counts all occurrences of _find in this string.
	size_t occurrences = 1
		+ this->CountMatches((nextOccurrence - this->str) + findLength, _find);
	char* newStr = new char[this->Length()
		+ (replaceLength - findLength) * occurrences
		+ 1];
	//Copies the beginning of this string, up to the first occurrence of _find,
	//into the new array.
	std::strncpy(newStr, this->str, (nextOccurrence - this->str));
	//Adding this null-terminator is necessary for strncat and strcat to work.
	newStr[nextOccurrence - this->str] = '\0';
	//Adds the first occurrence of _replace into the new array.
	std::strncat(newStr, _replace.str, replaceLength);
	//Loop over each subsequent occurrence of _find in this string.
	const char* prevOccurrence = nextOccurrence + findLength;
	while (
		(nextOccurrence = std::strstr(prevOccurrence, _find.str))
		!= nullptr)
	{
		//Copy all text from this string between the last occurrence of 
		// _find and the latest occurrence over to the new array.
		std::strncat(newStr, prevOccurrence, nextOccurrence - prevOccurrence);
		//Add a copy of _replace to the new array.
		std::strncat(newStr, _replace.str, replaceLength);
		prevOccurrence = nextOccurrence + findLength;
	}
	//Copy the remainder of the text from this string from the last occurence
	// of _find to the end of the string over to the new array.
	std::strcat(newStr, prevOccurrence);
	delete[] this->str;
	this->str = newStr;
	return *this;
}

//END OF JARED'S WORK -------------------------------------------------------------------------------

bool String::operator==(const String& _other) const		//Equal to operator, calls the EqualTo function using an operator
{
	return EqualTo(_other);
}

bool String::operator!=(const String& _other) const		//Does not equal operator, calls the inverse of the EqualTo function using an operator
{
	return !EqualTo(_other);
}

bool String::operator<(const String& _other) const		//Returns true if lhs is alphabetically before rhs, otherwise returns false.
{
	int a = strcmp(this->str, _other.str);
	if (a < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


String& String::operator=(const String& _str)			//Operator that updates (text A) with the new information from (text B) similar to 'replace'
{
	delete[] str;
	std::size_t _strLen = std::strlen(_str.str) + 1;
	str = new char[_strLen + 1];
	std::strncpy(str, _str.str, _strLen);
	return *this;
}

char& String::operator[](size_t _index)
{
	return str[_index];
}

const char& String::operator[](size_t _index) const
{
	return str[_index];
}
