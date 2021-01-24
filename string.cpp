#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <iostream>
String:: String(const char* str)
{
	size=strlen(str);
	this->str = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = str[i];
	}
	this->str[size] = '\0';
}
String:: String()
{
	str = nullptr;
	size = 0;
}
String:: String(const String& other)
{
	size = strlen(other.str);
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[size] = '\0';
}
String:: String (String&& other) noexcept
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
}
String& String:: operator = (const char* str)
{
	if (this->str != nullptr)
	{
		delete[] this->str;
	}
	size = strlen(str);
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = str[i];
	}
	this->str[size] = '\0';
	return *this;
}

String& String:: operator = (const String &other)
{
	if (this->str != nullptr)
	{
		delete[] this->str;
	}
	size = strlen(other.str);
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[size] = '\0';
	return *this;
}
String String:: operator + (const String& other)
{
	String newstr;
	int size1 = strlen(this->str);
	int size2 = strlen(other.str);
	newstr.str = new char[size1 + size2+1];
	int i=0;
	for (; i < size1; i++)
	{
		newstr.str[i] = this->str[i];
	}
	for (int j=0; j <size2; j++, i++)
	{
		newstr.str[i] = other.str[j];
	}
	newstr.str[strlen(this->str) + strlen(other.str)] = '\0';
	newstr.size = size1 + size2;
	return newstr;
}
bool String::operator == (const String& other)
{ 
	if (this->size != other.size)
		return false;
	for (int i = 0; i < this->size; i++)
	{
		if (this->str[i] != other.str[i])
			return false;
	}
	return true;
}
bool String::operator != (const String& other)
{
	return !(this->operator==(other));
}
char& String::operator[](int index)
{
	if (index<0 || index>size)
		std::cout << "Ошибочный индекс!" << std::endl;
		return this->str[index];
}
int String::length()
{
	return size;
}
String:: ~String()
{   if(str)
	delete[] this -> str;
}
std::ostream& operator << (std::ostream& out, const String& s)
{   
	out << s.str;
	return out;
}
std::istream& operator>>(std::istream& is, String& obj)
{
	char* BUFF= new char[2048];
	char a='-';
	int counter = 0;
	int count = 0;
	while (a != '\n')
	{
		a=is.get();
		if (a == ' ' || a=='\n')
			break;
		BUFF[counter] = a;
		counter++;
	}
	obj.str = new char[counter + 1];
	for (int i = 0; i < counter; i++)
	{
		obj.str[i] = BUFF[i];
	}
	obj.str[counter] = '\0';
	obj.size = strlen(obj.str);
	delete[] BUFF;
	return is;
}
char*& String::getStr()
{
	return str;
}
String & String:: erase(int start, int count)
{
	for (int i = start; i < size - count; i++)
	{
		str[i] = str[i + count];
	}
	size = size - count;
	str[size] = '\0';
	return *this;
}
long long int MyStoi(String& s)
{
	int i;
	long long int n;
	int a;
	n = 0;
	for (i = 0; s.str[i] >= '0' && s.str[i] <= '9'; ++i)
	{
		a = s.str[i] - '0';
	n = 10 * n + a;
     }
	return n;
}