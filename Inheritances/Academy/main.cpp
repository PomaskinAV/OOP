#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define tab "\t"

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	// Construction
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	// Methods:
	virtual ostream& print(ostream& os)const
	{
		cout.setf(ios::left);
		cout.width(10);
		return os << last_name << tab << first_name << tab << age;
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);
}

class Student:public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	// Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	):Human(last_name, first_name, age)// Делигируем конструктор базового класса
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	// Methods:
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os << tab;
		return os /*<< ", Специальность: "*/ << speciality << tab << tab << tab
			/*<< ", группа: "*/ << group
			/*<< ", успеваемость: "*/ << rating;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	// Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)// Делигируем конструктор базового класса
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	// Methods:
	ostream& print(ostream& os)const
	{
		cout.setf(ios::left);
		//cout.width(10);
		Human::print(os);
		os << tab;
		return os /*<< "Специальность: "*/ << speciality << tab
			/*<< ", опыт работы: "*/ << experience;
	}
};

class Graduate :public Student
{
	string diploma;
public:
	const string& get_diploma()const
	{
		return diploma;
	}
	void set_diploma(const string& diploma)
	{
		this->diploma = diploma;
	}
	// Constructors:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating, const string& diploma
	) :Student(last_name, first_name, age, speciality, group, rating)// Делигируем конструктор
	{
		set_diploma(diploma);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	// Methods:
	ostream& print(ostream& os)const
	{
		Student::print(os);
		cout.setf(ios::left);
		cout.width(10);
		return os /*<< "Тема дипломной работы работы: "*/ << tab << diploma;
	}
};

//#define INHERITANCE

	void main()
	{
		setlocale(LC_ALL, "");
#ifdef INHERITANCE
		Human h("Montana", "Antonio", 35);
		h.print();
		Student s("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93);
		s.print();
		Teacher t("Santa", "Claus", 45, "informatics", 20);
		t.print();
		Graduate g("Boris", "Jonson", 25, "Chemistry", "WW_03", 87, "Методы и средства криптографической защиты информации");
		g.print();
#endif // INHERITANCE

		//Generalisation:
		Human* group[] =
		{
			new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93),
			new Student("Verceti", "Tomas", 30, "Chemistry", "Vice", 90),
			new Teacher("White", "Walter", 50, "Chemistry", 25),
			new Student("Diaz", "Ricardo", 55, "Chemistry", "Vice", 80),
			new Graduate("Albert", "Hankuk", 42, "Cryminalistic", "OBN", 96, "How to catch Heisenberg"),
			new Teacher("Eistein", "Albert", 143, "Astronomy", 120),
		};

		//Specialisation
		for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
		{
			cout << "\n-----------------------------\n";
			//group[i]->print();
			cout << *group[i] << endl;
		}
		cout << "\n-----------------------------\n";

		ofstream fout("group.txt");
		for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
		{
			fout << *group[i] << endl;
		}
		fout.close();
		system("notepad group.txt");

		for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
		{
			delete[] group[i];
		}

		const int SIZE = 256;
		char buffer[SIZE] = {};

		ifstream fin("group.txt");
		if (fin.is_open())
		{
			while (!fin.eof())//Пока НЕ конец файла
			{
				//fin >> buffer;
				fin.getline(buffer, SIZE);
				cout << buffer << endl;
			}
		}
		else
		{
			cerr << "File not found" << endl;
		}
		fin.close();
	}