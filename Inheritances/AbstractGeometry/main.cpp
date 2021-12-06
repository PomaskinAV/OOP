#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<thread>
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
		blue = 0x0000FFFF,
		white=0x00FFFFFF
	};
	//enum - перечислени. Перечисление это набор именованных констант типа int

	const char* console_color[] =
	{
		"08",
		"19",
		"2A",
		"4C",
		"7F"
	};

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
		virtual void draw()const = 0;

		void start_draw()const
		{
			while (true)
			{
				draw();
			}
		}
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
		void draw()const
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
		void draw()const
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
		void draw()const
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

	class Triangle :public Shape
	{
	public:
		Triangle(Color color, unsigned int width, unsigned int start_x, unsigned int start_y) :Shape(color, width, start_x, start_y)
		{

		}
		~Triangle()
		{

		}
		virtual double get_height()const = 0;
	};

	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		void set_side(double side)
		{
			if (side <= 0) side = 1;
			this->side = side;
		}
		double get_area()const
		{
			return side * side * sqrt(3) / 4;
		}
		double get_perimetr()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, width, color);
			HBRUSH hBrash = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrash);

			const POINT points[] =
			{
				{start_x, start_y + this->get_height()},
				{start_x + side, start_y + this->get_height()},
				{start_x + side / 2, start_y}
			};
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));
			DeleteObject(hBrash);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		EquilateralTriangle(double side, Color color=Color::white, unsigned int width=5, unsigned int start_x=100, unsigned int start_y=100) :Triangle(color, width, start_x, start_y)
		{
			set_side(side);
		}
		~EquilateralTriangle()
		{

		}
	};

	class IsoscalesTriangle :public Triangle
	{
		double equal_sides;
		double footing;
	public:
		double get_equal_sides()const
		{
			return equal_sides;
		}
		double get_footing()const
		{
			return footing;
		}
		double get_height()const
		{
			return sqrt (pow(equal_sides, 2) - (pow(footing, 2)/4));
		}
		void set_equal_sides(double equal_sides)
		{
			if (equal_sides <= 0) equal_sides = 1;
			this->equal_sides = equal_sides;
		}
		void set_footing(double footing)
		{
			if (footing <= 0) footing = 1;
			this->footing = footing;
		}
		double get_area()const
		{
			return this->get_height() *(footing/2);
		}
		double get_perimetr()const
		{
			return (equal_sides * 2) + footing;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, width, color);
			HBRUSH hBrash = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrash);

			const POINT points[] =
			{
				{start_x, start_y},
				{start_x + footing/2, start_y + this->get_height()},
				{start_x + footing, start_y}
			};
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));
			DeleteObject(hBrash);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		IsoscalesTriangle(double equal_sides, double footing, Color color = Color::white, unsigned int width = 5, unsigned int start_x = 200, unsigned int start_y = 200) :Triangle(color, width, start_x, start_y)
		{
			set_equal_sides(equal_sides);
			set_footing(footing);
		}
		~IsoscalesTriangle()
		{

		}
	};

	class RightTriangle :public Triangle
	{
		double side1;
		double side2;
		double hypotenuse;
	public:
		double get_side1()const
		{
			return side1;
		}
		double get_side2()const
		{
			return side2;
		}
		double get_hypotenuse()const
		{
			return hypotenuse;
		}
		double get_height()const
		{
			return (side1*side2)/ hypotenuse;
		}
		void set_side1(double side1)
		{
			if (side1 <= 0) side1 = 1;
			this->side1 = side1;
		}
		void set_side2(double side2)
		{
			if (side2 <= 0) side2 = 1;
			this->side2 = side2;
		}
		void set_hypotenuse(double hypotenuse)
		{
			if (hypotenuse <= 0) hypotenuse = 1;
			this->hypotenuse = hypotenuse;
		}
		double get_area()const
		{
			return (side1*side2)/2;
		}
		double get_perimetr()const
		{
			return side1+side2+hypotenuse;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, width, color);
			HBRUSH hBrash = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrash);

			const POINT points[] =
			{
				{start_x, start_y},
				{start_x + side1, start_y + side2},
				{start_x + side1, start_y}
			};
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));
			DeleteObject(hBrash);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		RightTriangle(double side1, double side2, double hypotenuse, Color color = Color::white, unsigned int width = 5, unsigned int start_x = 200, unsigned int start_y = 200) :Triangle(color, width, start_x, start_y)
		{
			set_side1(side1);
			set_side2(side2);
			set_hypotenuse(hypotenuse);
		}
		~RightTriangle()
		{

		}
	};
}

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = {80, 50};
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);
	system("pause");
	setlocale(LC_ALL, "");
	/*Geometry::Square square(5, Geometry::Color::console_red);
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimetr() << endl;
	square.draw();*/

	//Geometry::Rectangle rectangle(100, 200, Geometry::Color::green, 5, 200, 100);
	////cout << "Площадь прямоугольника: " << rectangle.get_area() << endl;
	////cout << "Периметр прямоугольника: " << rectangle.get_perimetr() << endl;
	//rectangle.draw();

	//Geometry::Circle circle(50, Geometry::Color::green, 5, 200, 100);
	////cout << "Площадь круга: " << rectangle.get_area() << endl;
	////cout << "Периметр круга: " << rectangle.get_perimetr() << endl;
	//circle.draw();
	
	char key = 0;

	Geometry::Rectangle rect1(100, 200, Geometry::Color::yellow, 5, 100, 100);
	cout << rect1.get_area() << endl;
	cout << rect1.get_perimetr() << endl;
	
	/*while (key != ' ')
	{
		rect1.draw();
		if (_kbhit())key = getch();
	}*/
	std::thread rect1_thread(&Geometry::Rectangle::start_draw, rect1);

	cout << "\n-----------------------------\n";
	Geometry::EquilateralTriangle et(300, Geometry::Color::green, 5, 100, 300);
	cout << et.get_height() << endl;
	cout << et.get_area() << endl;
	cout << et.get_perimetr() << endl;
	/*cin.get();
	et.draw();
	cin.get();*/
	key = 0;
	/*while (key!=' ')
	{
		et.draw();
		if (_kbhit())key = getch();
	}*/
	std::thread et_thread(&Geometry::EquilateralTriangle::start_draw, et);
	//Sleep(10000);

	Geometry::IsoscalesTriangle it(300, 200, Geometry::Color::red, 5, 350, 100);
	cout << it.get_height() << endl;
	cout << it.get_area() << endl;
	cout << it.get_perimetr() << endl;
	
	key = 0;
	
	std::thread it_thread(&Geometry::IsoscalesTriangle::start_draw, it);

	Geometry::RightTriangle rt(300, 200, 500, Geometry::Color::blue, 5, 700, 100);
	cout << rt.get_height() << endl;
	cout << rt.get_area() << endl;
	cout << rt.get_perimetr() << endl;

	key = 0;

	std::thread rt_thread(&Geometry::RightTriangle::start_draw, rt);

	cin.get();
	et_thread.join();
	rect1_thread.join();
	it_thread.join();
	rt_thread.join();
}