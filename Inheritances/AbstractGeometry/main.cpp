#include<iostream>
using namespace std;

enum Color
{
	console_gray=0x88,
	console_blue=0x99,
	console_green = 0xAA,
	console_red = 0xCC,
	console_white=0xFF
};
//enum - перечислени. Перечисление это набор именованных констант типа int

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color)
	{
		cout << "ShConstructor:\t" << this << endl;
	}
	virtual ~Shape()
	{
		cout << "ShDestructor:\t" << this << endl;
	}
	virtual double get_area()const = 0;
	virtual double get_perimetr()const = 0;
	virtual void get_draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side <= 0)side = 1;
		this->side = side;
	}
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	~Square()
	{

	}

	double get_area()const
	{
		return side * side;
	}
	double get_perimetr()const
	{
		return side * 4;
	}
	void get_draw()const
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

class Rectangle :public Shape
{
	double side1;
	double side2;
public:
	double get_side1()const
	{
		return side1;
	}
	double get_side2()const
	{
		return side2;
	}
	void set_side1(double side1)
	{
		if (side1 <= 0)side1 = 1;
		this->side1 = side1;
	}
	void set_side2(double side2)
	{
		if (side2 <= 0)side2 = 1;
		this->side2 = side2;
	}
	Rectangle(double side1, double side2, Color color) :Shape(color)
	{
		set_side1(side1);
		set_side2(side2);
	}
	~Rectangle()
	{

	}

	double get_area()const
	{
		return side1 * side2;
	}
	double get_perimetr()const
	{
		return (side1+side2) * 2;
	}
	void get_draw()const
	{
		for (int i = 0; i < side1; i++)
		{
			for (int j = 0; j < side2; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Square square(5, Color::console_red);
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Перимеитр квадрата: " << square.get_perimetr() << endl;
	square.get_draw();
	Rectangle rectangle(5, 7, Color::console_red);
	cout << "Площадь прямоугольника: " << rectangle.get_area() << endl;
	cout << "Периметр прямоугольника: " << rectangle.get_perimetr() << endl;
	rectangle.get_draw();
}