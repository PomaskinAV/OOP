#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// constuctors:
	Point()
	{
		x = 0;
		y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	// increment/decrement
	Point& operator++()
	{
		this->x++;
		this->y++;
		cout << "PrefixIncrement:\t" << this << endl;
		return *this;
	}
	Point operator++(int) //Suffix increment
	{
		Point old = *this; //сохраняем текущее значение нашего объекта
		this->x++;
		this->y++;
		cout << "SuffixIncrement:\t" << this << endl;
		return old;
	}

	// methods:
	double distance(const Point& other)
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
			return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
		//pow - возведение в степень
		//sqrt (Square Root) - квадратный корень
	}
	void print()const
	{
		cout << "X = " << x << "\t" << "Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point buffer;
	buffer.set_x(left.get_x() + right.get_x());
	buffer.set_y(left.get_y() + right.get_y());
	return buffer;
}

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X= " << obj.get_x() << "\t" << "Y= " << obj.get_y();
	return os;
}
istream& operator>>(istream& is, Point& obj)
{
	double x, y;
	is >> x;
	is >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

#define delimetr "\n-----------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARIFMATICAL_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT 
	Point A; //Объявление переменной А типа Point
// Создание объекта А структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B;
	B.set_x(3);
	B.set_y(4);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();

	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimetr << endl;
	cout << "Расстояние от точки А до точки В: " << B.distance(A) << endl;
	cout << delimetr << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << delimetr << endl;
	cout << "Расстояние между точками В и А: " << distance(B, A) << endl;
	cout << delimetr << endl;
#endif // DISTANCE

#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
	A.print();
	Point B(2, 3);
	B.print();

	Point C = B; //Copy constructor
	C.print();

	Point D;
	D = B; // Copy assignment - оператор присваивания
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3); //Point(2, 3) явный вызов конструктора
	// таким образом создается временный безымянный объект
	// который существует только в пределах выражения,
	// и удаляется после завершения выражения.
	cout << delimetr << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

#ifdef ARIFMATICAL_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	Point C = A + B; //чтобы научить оператор + складывать точки, его нужно перегрузить для класса точка
	C.print();
#endif // ARIFMATICAL_CHECK

	/*for (Point i(2, 3); i.get_x() < 10; i++)
	{
		i.print();
	}*/
	Point A(2, 3);
	Point B = A++;
	/*A.print();
	B.print();*/
	cout << A << endl;
	cout << B << endl;

	cout << "Введите координаты точки А: ";
	cin >> A;
	cout << A << endl;
}