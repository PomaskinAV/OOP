#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer; //целая часть
	int numerator; //числитель
	int denominator; //знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleConstructor:" << this << endl;
	}
	/*explicit Fraction(double dec)
	{
		integer = dec;
		dec -= integer;
		dec *= 1000;
		numerator = dec;
		denominator = 1000;
		reduce();
	}*/
	Fraction(double dec)
	{
		dec += 1e-11;
		integer = dec; //сохраняем целую часть десятичной дроби
		dec -= integer; //убираем целую часть издесятичной дроби
		denominator = 1e+9; //1 * на 10 в 9 степени
		numerator = dec * denominator;//умножаем дробную часть десятичной дроби на 1000000000
		//и таким образом вся дробная часть переходит в целую часть. и сохраняем ее в числителе
		reduce();
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}
	//Operator
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction operator+=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = numerator * other.denominator + this->denominator * other.numerator;
		this->denominator *= other.denominator;
		return this->to_proper();
	}
	Fraction operator-=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = numerator * other.denominator - this->denominator * other.numerator;
		this->denominator *= other.denominator;
		return this->to_proper();
	}
	/*Fraction& operator*=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return this->to_proper();
	}
	Fraction& operator/=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator *= other.denominator;
		this->denominator *= other.numerator;
		return this->to_proper();
	}*/
	Fraction& operator++()
	{
		to_proper();
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		to_proper();
		Fraction buffer = *this;
		integer++;
		return buffer;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction buffer = *this;
		integer--;
		return buffer;
	}

	// Type-cast
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	// Methods
	Fraction& to_proper()
	{
		//переводит дробь в правильную
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//переводит дробь в неправильную
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& invert()
	{
		to_improper();
		int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;
	}

	Fraction reduce()
	{
		if (numerator == 0)
		{
			denominator = 1;
			return *this;
		}
		int more;
		int less;
		int rest; //остаток от деления
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //наибольший общий делитель
		numerator /= GCD;
		denominator /= GCD;
		return to_proper();
	}
	void print()
	{
		if(integer)cout << integer; //если есть целая часть, то выводим ее на экран
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	
};

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())cout << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())cout << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())cout << ")";
	}
	else if (obj.get_integer() == 0)cout << 0;
	return os;
}

istream& operator>>(istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer;
	is >> numerator;
	is >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;*/

	const int SIZE = 50;
	char buffer[SIZE] = {};
	char delimiters[] = " ()/";
	//is >> buffer;
	is.getline(buffer, SIZE);
	char* value[3] = {};
	int n = 0;
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		value[n++] = pch;
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << value[i] << "\t";
	}
	cout << endl;*/
	switch (n)
	{
	case 1: obj.set_integer(atoi(value[0])); break;
	case 2: obj.set_numerator(atoi(value[0]));
		obj.set_denominator(atoi(value[1])); break;
	case 3: obj.set_integer(atoi(value[0]));
		obj.set_numerator(atoi(value[1]));
		obj.set_denominator(atoi(value[2]));
	}
	return is;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);*/
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//result.to_proper();
	//return result;
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);*/
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//result.to_proper();
	//return result;
	/*return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();*/
	return left * right.invert();
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction(left.get_integer() + right.get_integer(), left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator());
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	return Fraction(left.get_integer() - right.get_integer(), left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator());
}

// Comparison operators:
bool operator == (Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
		//return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
	return left.to_improper().get_numerator() * right.get_denominator() ==
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction left, const Fraction right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator() * right.get_denominator() >
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator() * right.get_denominator() <
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	//return left < right || left == right;
	return !(left > right);
}

//#define CONSTRUCTORS_CHECK
//#define OSTREAM_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS
//#define ISTREAM_OPERATOR_CHECK
//#define TYPE_CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Default constructor
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef OSTREAM_CHECK
	Fraction A(14, 4);
	A.to_proper();
	//A.print();
	cout << A << endl;
	A.to_improper();
	//A.print();
	cout << A << endl;
#endif // OSTREAM_CHECK

#ifdef ARIFMETICAL_OPERATORS_CHECK
	Fraction A(2, 3);
	Fraction B(2, 5);
	Fraction C = A * B;
	cout << C << endl;
	Fraction D = A / B;
	cout << D << endl;
	Fraction E = A + B;
	cout << E << endl;
	Fraction F = A - B;
	cout << F << endl;
	Fraction G(1, 3);
	G++;
	cout << G << endl;
	Fraction H(3, 1, 3);
	H--;
	cout << H << endl;
#endif // ARIFMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS
	Fraction A(1, 5, 10);
	Fraction B(1, 100, 220);
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
#endif // COMPARISON_OPERATORS

#ifdef ISTREAM_OPERATOR_CHECK
	Fraction A;
	cout << "Введите дробь: ";
	cin >> A;
	cout << A << endl;
#endif // ISTREAM_OPERATOR_CHECK

#ifdef TYPE_CONVERSION_BASICS
	int a = 2;
	double b = 3;
	int c = b;
	int d = 4.5;
	cout << d << endl;
#endif // TYPE_CONVERSION_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	double a = 2;
	Fraction A = (Fraction)5;
	cout << A << endl;
	cout << "\n-----------------------------\n";
	Fraction B;
	cout << "\n-----------------------------\n";
	B = (Fraction)8;
	cout << "\n-----------------------------\n";
	cout << B << endl;

	Fraction C(12); //explicit конструктор можно вызвать только так и нельзя Fraction C =12;
	cout << C << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	int a = (int)A;
	cout << A << endl;
	cout << a << endl;
	double b = (double)A;
	cout << b << endl;
	Fraction C = (Fraction)b;
	cout << C << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

	Fraction A = 2.76;
	cout << A << endl;
	Fraction B(2, 76, 100);
	cout << B << endl;
	cout << (A == B) << endl;

	Fraction C(1, 3);
	cout << C*3 << endl;
}