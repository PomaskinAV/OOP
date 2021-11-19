#pragma once
#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

//ќбъ€вление класса - class declaration

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size; //размер строки в байтах
	char* str; //адрес строки в динамичесокй пам€ти
public:
	int get_size()const;
	char* get_str();
	const char* get_str()const;

	//	Constructor
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:
	String& operator=(const String& other);

	String& operator=(String& other);

	String& operator+=(const String& other);

	const char& operator[](int i)const;

	char& operator[](int i);

	void print()const;
};
// онец объ€влени€ класса