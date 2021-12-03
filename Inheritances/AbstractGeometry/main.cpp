#include<iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		console_gray = 0x88,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_white = 0xFF,
		console_default = 0x07,

		red = 0x000000FF,
		green = 0x0000FF00,
		dark_green = 0x0000AA00,
		yellow = 0x00FF00FF,
		blue = 0x0000FFFF
	};
	//enum - перечислени. Перечисление это набор именованных констант типа int

	class Shape
	{
	protected:
		Color color;
		unsigned int width;
		//начальные координаты для рисования финуры
		unsigned int start_x;
		unsigned int start_y;
	public:
		unsigned int get_width()const
		{
			return width;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		void set_width(unsigned int width)
		{
			if (width > 20)width = 20;
			this->width = width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 1000)start_x = 1000;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 700)start_y = 700;
			this->start_y = start_y;
		}
		Shape(Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :color(color)
		{
			set_width(width);
			set_start_x(start_x);
			set_start_y(start_y);
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
		Square(double side, Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
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
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
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
			if (side2 <= 0)side2 = 2;
			this->side2 = side2;
		}
		Rectangle(double side1, double side2, Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
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
			return (side1 + side2) * 2;
		}
		void get_draw()const
		{
			//1)Получаем окно консоли
			//HWND hwnd = GetConsoleWindow();
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			//2)Создаем контекст устройства  полученного окна
			HDC hdc = GetDC(hwnd);
			//3)Создаем карандаш
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			//4) Нужно выбрать карандаш
			SelectObject(hdc, hPen);

			//чтобы фигура была закрашена определенным цветом, нужно создать кисть
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x+side2, start_y+side1);

			DeleteObject(hBrush);
			// Удаляем карандаш
			DeleteObject(hPen);
			// Все контексты устройств нужно удалять чтобы освободить занимаемые ими русурсы
			ReleaseDC(hwnd, hdc);
			/*for (int i = 0; i < side1; i++)
			{
				for (int j = 0; j < side2; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}*/
		}
	};

	class Circle :public Shape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius <= 0)radius = 1;
			this->radius = radius;
		}
		Circle(double radius, Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
		{
			set_radius(radius);
		}
		~Circle()
		{

		}
		double get_area()const
		{
			return 3.14 * pow(get_radius(), 2);
		}
		double get_perimetr()const
		{
			return (2 * 3.14 * get_radius());
		}
		void get_draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			SelectObject(hdc, hPen);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hBrush);
			::Ellipse(hdc, 100, 200, 200, 400);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	/*Geometry::Square square(5, Geometry::Color::console_red);
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimetr() << endl;
	square.get_draw();*/

	//Geometry::Rectangle rectangle(100, 200, Geometry::Color::green, 5, 200, 100);
	////cout << "Площадь прямоугольника: " << rectangle.get_area() << endl;
	////cout << "Периметр прямоугольника: " << rectangle.get_perimetr() << endl;
	//rectangle.get_draw();

	Geometry::Circle circle(50, Geometry::Color::green, 5, 200, 100);
	//cout << "Площадь круга: " << rectangle.get_area() << endl;
	//cout << "Периметр круга: " << rectangle.get_perimetr() << endl;
	circle.get_draw();
}