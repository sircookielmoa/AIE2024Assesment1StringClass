#include "String.h"
#include <cctype>
#include <cstring>
#include <iostream>

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

size_t String::Length() const
{
	return std::strlen(str);
}

char& String::CharacterAt(size_t _index)
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

String& String::ToLower()
{
	std::tolower;

	return *this;
}

String& String::ToUpper()
{
	std::toupper;

	return* this;
}

String& String::WriteToConsole()
{
	std::cout << str << std::endl;
	return *this;
}