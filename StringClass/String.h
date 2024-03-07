#pragma once

class String
{
private:
	char* str;

public:
	String();
	String(const char* _str);

	String(const String& _other);

	~String();

public:
	size_t Length() const;
	char& CharacterAt(size_t _index);
	const char& CharacterAt(size_t _index) const;

	bool EqualTo(const String& _other) const;

	String& Append(const String& _str);
	String& Prepend(const String& _str);

	const char* CStr() const;

	String& ToLower();
	String& ToUpper();

	size_t Find(const String& _str) const;
	size_t Find(size_t _startIndex, const String& _str) const;

	String& Replace(const String& _find, const String& _replace);

	String& ReadFromConsole();
	const String& WriteToConsole() const;

	size_t CountMatches(size_t _startIndex, const String& _find) const;


public:
	bool operator==(const String& _other) const;
	bool operator!=(const String& _other) const;
	bool operator<(const String& _other) const;

	String& operator=(const String& _str);

	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;

private:
/*
* Put your internal data structures and members here
*/
};
