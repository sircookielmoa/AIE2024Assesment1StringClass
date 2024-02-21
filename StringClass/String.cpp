#include "String.h"
#include <cstring>

String::String()
{
	null = 0;
	str = new char[0];
	length = 0;
}

String::String(const char* _str)
	: str(nullptr)
{
	//1. Figure out how much sext _str is pointing at
	std::size_t _strLen = std::strlen(_str) + 1;
	//2. Make str point at an arrau big enough to fit the text in _str
	str = new char[_strLen + 1];
	//3. Copy the text from _str to str.
	std::strncpy(str, _str, _strLen);
}

String::String(const String& _other)
	: str(nullptr)
{

}

String::~String()
{
	delete[] str;
}
