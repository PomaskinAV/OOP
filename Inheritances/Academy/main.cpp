#include<iostream>
#include<string>
#include<fstream>
using namespace std;

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
		//cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		//cout << "HDestructor:\t" << this << endl;
	}
	// Methods:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " "
		<< obj.get_first_name() << " "
		<< obj.get_age() << " лет.";
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
		//cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		//cout << "SDestructor:\t" << this << endl;
	}
	// Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality
			<< ", группа: " << group
			<< ", успеваемость: " << rating << endl;
	}
};

ostream& operator<<(ostream& os, const Student& obj)
{
	os << (Human)obj;
	return os << ", спец:" << obj.get_speciality()
		<< ", группа:" << obj.get_group()
		<< ", успеваемость:" << obj.get_rating();
}

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
		//cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		//cout << "TDestructor:\t" << this << endl;
	}
	// Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality
			<< ", опыт работы: " << experience << endl;
	}
};

ostream& operator<<(ostream& os, const Teacher& obj)
{
	return
		os << (Human)obj <<", спец:" << obj.get_speciality()
		<< ", опыт преподавания:" << obj.get_experience();
}

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
		//cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		//cout << "GDestructor:\t" << this << endl;
	}
	// Methods:
	void print()const
	{
		Student::print();
		cout << "Тема дипломной работы работы: " << diploma << endl;
	}
};

ostream& operator<<(ostream& os, const Graduate& obj)
{
	return os << (Student)obj << "Тема" << obj.get_diploma();
}

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
			new Student("Vercetti", "Tomas", 30, "Chemistry", "Vice", 90),
			new Teacher("White", "Walter", 50, "Chemistry", 25),
			new Student("Diaz", "Ricardo", 55, "Weapons dastribution", "Vice", 80),
			new Graduate("Schraden", "Hank", 42, "Cryminalistic", "OBN", 96, "How to catch Heisenberg"),
			new Teacher("Eistein", "Albert", 143, "Astronomy", 120),
		};
		ofstream fout("File.txt", std::ios_base::app);
		//Specialisation
		for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
		{
			cout << "\n-----------------------------\n";
			//group[i]->print();
			//cout << *group[i] << endl;
			//cout << typeid(*group[i]).name() << endl;
			if (typeid(*group[i]) == typeid(Student)) cout << *dynamic_cast<Student*>(group[i]) << endl;
			if (typeid(*group[i]) == typeid(Graduate)) cout << *dynamic_cast<Graduate*>(group[i]) << endl;
			if (typeid(*group[i]) == typeid(Teacher)) cout << *dynamic_cast<Teacher*>(group[i]) << endl;

			//fout << *group[i] << endl;
		}
		cout << "\n-----------------------------\n";
		fout.close();




		for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
		{
			delete[] group[i];
		}

		cout << endl;


		const int SIZE = 256;
		char buffer[SIZE] = {};

		ifstream fin("File.txt");
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