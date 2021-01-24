
#ifndef STRING_H
#define STRING_H
#pragma once
#include <iostream>
class String
{
private:
	char *str;
	int size;
public:
	String();
	String(const char *str);
	String(const String& other);
	String (String&& other) noexcept;
	~String();
	String& operator = (const char *str);
	String& operator = (const String& other);
	String operator + (const String& other);
	bool operator == (const String& other);
	bool operator != (const String& other);
	char& operator[](int index);
	int length();
	char*& getStr();
	String & erase(int start, int count);
	friend long long int MyStoi(String& s);
	friend std::ostream & operator <<(std::ostream& out, const String& str);
	friend std::istream& operator >>(std::istream& stream, String& str);
};
#endif
