#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleConstructor:" << this << endl;
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
	

	// Methods
	void to_proper()
	{
		//переводит дробь в правильную
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		//переводит дробь в неправильную
		numerator += integer * denominator;
		integer = 0;
	}
	void reduce()
	{
		//сокращает дробь

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
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
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
	cout << endl;
	return os;
}

istream& operator>>(istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer;
	is >> numerator;
	is >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;
}

Fraction operator*(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
}

Fraction operator/(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator() / right.get_numerator(), left.get_denominator() / right.get_denominator());
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction(left.get_integer() + right.get_integer(), left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator());
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	return Fraction(left.get_integer() - right.get_integer(), left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator());
}

//#define CONSTRUCTORS_CHECK

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

	//Fraction A(14, 4);
	//A.to_proper();
	////A.print();
	//cout << A << endl;
	//A.to_improper();
	////A.print();
	//cout << A << endl;
	Fraction A(4, 8);
	Fraction B(1, 3);
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
	Fraction J;
	cout << "Введите значения дроби: ";
	cin >> J;
	cout << J << endl;
}