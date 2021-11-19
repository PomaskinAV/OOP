#include"String.h"


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