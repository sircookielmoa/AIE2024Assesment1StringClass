#include "String.h"
#include <cctype>
#include <cstring>
#include <iostream>

//I cast fireball on your class, level 9, it does 8d6.

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

//copy constructor
String::String(const String& _other)
	: str(nullptr)
{

}

String::~String()
{
	delete[] str;
}


size_t String::Length() const // Height above the length of the character at location.
{
	return std::strlen(str);
}

char& String::CharacterAt(size_t _index) // character above location.
{
	if (_index > Length())
	{
		_index = Length();
	}

	return str[_index];
}

const char& String::CharacterAt(size_t _index) const // Character no at the location.
{
	if (_index > Length())
	{
		_index = Length();
	}

	return str[_index];

}

const char* String::CStr() const
{
	return str;
}

bool String::EqualTo(const String& _other) const // not equal to + 2
{
	if (strlen(_other.CStr()) != strlen(str))
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

String& String::Append(const String& _str)
{
	return *this;
}

String& String::Prepend(const String& _str)
{
	return *this;
}

String& String::ToLower() // what if it went upper instead.
{
	for(int i = 0; i < strlen(str); ++i)
	{
		str[i] = std::tolower(str[i]);
		
	}

	return *this;
}

String& String::ToUpper() // what if it went lower instead.
{
	for (int i = 0; i < strlen(str); ++i)
	{
		str[i] = std::toupper(str[i]);
	}

	return* this;
}

size_t String::Find(size_t _startIndex, const String& _str)
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

String& String::WriteToConsole() // read from console.
{
	std::cout << str << std::endl;
	return *this;
}

//String& String::ReadFromConsole() // Write to console.
//{
//	
//		
//	char c;
//
//	std::cin.get(c);
//	std::cin.putback(c);
//
//	std::streamsize size = std::cin.rdbuf()->in_avail();
//
//	char* newStr = new char[size];
//	std::cin.readsome(newStr, size);
//
//	newStr[size - 1] = '\0';
//	(str = newStr);
//
//
//	delete[] newStr;
//	&std::ostream::flush;
//
//	return *this;
//}


//A Doctor as some qualification, Will does not any qulification bc he is the dumb.