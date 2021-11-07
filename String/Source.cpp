#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	void set_size(int size)
	{
		this->size = size;
	}
	void set_str(char* str)
	{
		this->str = str;
	}
	//	Constructor
	String()
	{
		this->size = 80;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:

};

ostream& operator<<(ostream& os, const String& obj)
{
	os << obj.get_str();
	return os;
}

void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello";
	String str2 = "World";
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;
}