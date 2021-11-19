#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

//ќбъ€вление класса - class declaration

class String;
String operator+(const String& left, const String& right);

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

//ќпределение класса
int String::get_size()const
{
	return size;
}
char* String::get_str()
{
	return str;
}
const char* String::get_str()const
{
	return str;
}
//	Constructor
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1) //ƒелегируем выделение памати конструктору по умолчанию
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	cout << "MoveConstructor:\t" << this << endl;
	other.str = nullptr;
	other.size = 0;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssigment:\t\t" << this << endl;
	return *this;
}

String& String::operator=(String& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	other.size;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i)const
{
	return str[i];
}

char& String::operator[](int i)
{
	return str[i];
}

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

//:: - Global scope (глобальное пространстро имен)
::String operator+(const String& left, const String& right)
{
	String result (left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
	result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i+left.get_size()-1] = right.get_str()[i];
	result[i + left.get_size() - 1] = right[i];

	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

// онец определени€ класса

//#define CONSTRUCTOR_CHECK
//#define OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	String str;
	str.print();
	String str1 = "Hello";
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;
	cout << str2 << endl;
	String str3;
	str3 = str2;
	cout << str3 << endl;
#endif // CONSTRUCTOR_CHECK

#ifdef OPERATORS_CHECK
	/*String str1 = "Hello";
str1 = str1;
cout << str1 << endl;*/
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
	/*str1 += str2;
	cout << str1 << endl;*/
#endif // OPERATORS_CHECK

	String str1(25); //Default constructor;
	str1.print();
	String str2 = "Hello"; //Single-argument constructor
	//cout << str2 << endl;
	str2.print();
	String str3("World"); //Single-argument constructor
	cout << str3 << endl;
	String str4(); //«десь не создаетс€ объект, а ќбъ€вл€ем функцию str4, котора€ ни чего не принимает и возвращает объект класса String
	//cout << str4 << endl;
	String str5{}; //явный вызов конструктора по умолчанию
	cout << str5 << endl;
	String str6{ "ѕараметры в конструктор можно передавать в фигурных скобках" };
	cout << str6 << endl;
	String str7 = str6;
	cout << str7 << endl;
	cout << str2 +" "+ str3 << endl;
}