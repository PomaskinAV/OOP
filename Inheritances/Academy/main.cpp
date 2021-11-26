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
		/*cout.setf(ios::left);
		cout.width(10);
		return os << last_name << tab << first_name << tab << age;*/
		os.width(10);
		os << std::left;
		os << last_name;
		os.width(10);
		os << std::left;
		os << first_name;
		os.width(5);
		os << std::left;
		os << age;
		return os;
	}
	virtual ofstream& print(ofstream& os)const
	{
		os.width(15);
		os << left;
		os << typeid(*this).name() << " | ";
		/*cout.setf(ios::left);
		cout.width(10);
		return os << last_name << tab << first_name << tab << age;*/
		os.width(10);
		os << std::left;
		os << last_name << "|";
		os.width(10);
		os << std::left;
		os << first_name << "|";
		os.width(5);
		os << std::left;
		os << age << "|";
		return os;
	}
	virtual istream& input(istream& is)
	{
		return is >> last_name >> first_name >> age;
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);
}
ofstream& operator<<(ofstream& os, const Human& obj)
{
	return obj.print(os);
}
istream& operator>>(istream& is, Human& obj)
{
	/*string last_name, first_name;
	int age;
	is >> last_name >> first_name >> age;
	obj.set_last_name(last_name);
	obj.set_first_name(first_name);
	obj.set_age(age);
	return is;*/
	return obj.input(is);
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
		//os << tab;
		//return os /*<< ", Специальность: "*/ << speciality << tab << tab << tab
		//	/*<< ", группа: "*/ << group
		//	/*<< ", успеваемость: "*/ << rating;
		os.width(25);
		os << left;
		os << speciality;
		os.width(8);
		os << left;
		os << group;
		os.width(5);
		//os << right;
		os << internal;
		os << rating;
		os << "%";
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		//os << tab;
		//return os /*<< ", Специальность: "*/ << speciality << tab << tab << tab
		//	/*<< ", группа: "*/ << group
		//	/*<< ", успеваемость: "*/ << rating;
		os.width(25);
		os << left;
		os << speciality << "|";
		os.width(8);
		os << left;
		os << group << "|";
		os.width(5);
		//os << right;
		os << internal;
		os << rating;
		os << "% |";
		return os;
	}
	istream& input(istream& is)
	{
		Human::input(is);
		is >> speciality;
		is >> group;
		is >> rating;
		return is;
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
		/*cout.setf(ios::left);*/
		//cout.width(10);
		Human::print(os);
		//os << tab;
		//return os /*<< "Специальность: "*/ << speciality << tab
		//	/*<< ", опыт работы: "*/ << experience;
		os.width(33);
		os << speciality;
		os.width(5);
		os << right;
		os << experience << "y";
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		/*cout.setf(ios::left);*/
		//cout.width(10);
		Human::print(os);
		//os << tab;
		//return os /*<< "Специальность: "*/ << speciality << tab
		//	/*<< ", опыт работы: "*/ << experience;
		os.width(33);
		os << speciality << " | ";
		os.width(5);
		os << right;
		os << experience << "y|";
		return os;
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
		//cout.setf(ios::left);
		//cout.width(10);
		//return os /*<< "Тема дипломной работы работы: "*/ << tab << diploma;
		return os << left << " " << diploma;
	}
	ofstream& print(ofstream& os)const
	{
		Student::print(os);
		//cout.setf(ios::left);
		//cout.width(10);
		//return os /*<< "Тема дипломной работы работы: "*/ << tab << diploma;
		os << left << " " << diploma;
		return os;
	}
};

void SaveToFile(const Human* group[], const int size, const string& filename);
Human** LoadFromFile(const std::string& filename);

//#define INHERITANCE
//#define OUTPUT_CHECK

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

#ifdef OUTPUT_CHECK
		//Generalisation:
		Human* group[] =
		{
			new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 5),
			new Student("Verceti", "Tomas", 30, "Chemistry", "Vice", 100),
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

		/*ofstream fout("group.txt");
		for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
		{
			fout << *group[i] << endl;
		}
		fout.close();
		system("notepad group.txt");*/
		string filename = "group.txt";
		SaveToFile(group, sizeof(group) / sizeof(group[0]), "group.txt");
		system((string("notepad ")+ filename).c_str());

		for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
		{
			delete[] group[i];
		}

#endif // OUTPUT_CHECK

		/*Human human("last_name", "first_name", 0);
		cout << "Кто к нам пришел: ";
		cin >> human;
		cout << human << endl;*/
		/*Student stud("", "", 0, "", "", 0);
		cout << "Кто к нам пришел: ";
		cin >> stud;
		cout << stud << endl;*/

		LoadFromFile("group.txt");
	}

	void SaveToFile(const Human* group[], const int size, const string& filename)
	{
		ofstream fout(filename);
		for (int i = 0; i < size; i++)
		{
			fout << *group[i] << endl;
		}
		fout.close();
	}
	Human** LoadFromFile(const std::string& filename)
	{
		ifstream fin(filename);
		if (fin.is_open())
		{
			std::string buffer;
			int n = 0;
			while (!fin.eof())
			{
				std::getline(fin, buffer);
				n++;
			}
			Human** group = new Human * [n] {};
			fin.clear();
			fin.seekg(0);
			for (int i = 0; i < n; i++)
			{
				std::getline(fin, buffer);
				cout << buffer << endl;
			}
		fin.close();
		}
		else
		{
			cerr << "Error: File not found!" << endl;
		}
		return nullptr;
	}