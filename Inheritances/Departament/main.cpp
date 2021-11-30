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
		os.width(16);
		os << left;
		os << typeid(*this).name() << " | ";
		os.width(10);
		os << std::left;
		os << last_name << "|";
		os.width(15);
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
	virtual ifstream& input(ifstream& is)
	{
		std::getline(is, last_name, '|');
		std::getline(is, first_name, '|');
		string age_buffer;
		std::getline(is, age_buffer, '|');
		this->age = std::stoi(age_buffer);
		return is;
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
	return obj.input(is);
}
ifstream& operator>>(ifstream& is, Human& obj)
{
	return obj.input(is);
}

class Accounting :public Human
{
	string post;
	unsigned int experience;
	double salary;
public:
	const string& get_post()const
	{
		return post;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	double get_salary()const
	{
		return salary;
	}
	void set_post(const string& post)
	{
		this->post = post;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}
	// Constructors:
	Accounting
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& post, unsigned int experience, double salary
	) :Human(last_name, first_name, age)// Делигируем конструктор базового класса
	{
		set_post(post);
		set_experience(experience);
		set_salary(salary);
		cout << "SConstructor:\t" << this << endl;
	}
	~Accounting()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	// Methods:
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os.width(16);
		os << left;
		os << post;
		os.width(8);
		os << right;
		os << experience << "y";
		os.width(40);
		os << right;
		os << salary << "rub";
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os.width(16);
		os << left;
		os << post << "|";
		os.width(8);
		os << right;
		os << experience << "y|";
		os.width(42);
		os << right;
		os << salary << "rub|";
		return os;
	}
	istream& input(istream& is)
	{
		Human::input(is);
		is >> post;
		is >> experience;
		is >> salary;
		return is;
	}
	ifstream& input(ifstream& is)
	{
		Human::input(is);
		std::getline(is, post, '|');
		string xp_buffer;
		std::getline(is, xp_buffer, '|');
		experience = std::stod(xp_buffer);
		string salary_buffer;
		std::getline(is, salary_buffer, '|');
		this->salary = std::stod(salary_buffer);
		return is;
	}
};

class Logistics :public Human
{
	string post;
	unsigned int experience;
	double time_worked;
	double norm_hour;
	double salary;
public:
	const string& get_post()const
	{
		return post;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	double get_time_worked()const
	{
		return time_worked;
	}
	double get_norm_hour()const
	{
		return norm_hour;
	}
	double get_salary()const
	{
		return salary;
	}
	void set_post(const string& post)
	{
		this->post = post;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	void set_time_worked(double time_worked)
	{
		this->time_worked = time_worked;
	}
	void set_norm_hour(double norm_hour)
	{
		this->norm_hour = norm_hour;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}
	// Constructors:
	Logistics
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& post, unsigned int experience, double time_worked, double norm_hour
	) :Human(last_name, first_name, age)// Делигируем конструктор базового класса
	{
		set_post(post);
		set_experience(experience);
		set_time_worked(time_worked);
		set_norm_hour(norm_hour);
		set_salary(salary);
		cout << "LConstructor:\t" << this << endl;
	}
	~Logistics()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	// Methods:
	ostream& print(ostream& os)const
	{
		Human::print(os);
		os.width(16);
		os << left;
		os << post;
		os.width(8);
		os << right;
		os << experience << "y";
		os.width(8);
		os << right;
		os << time_worked << "hour";
		os.width(8);
		os << right;
		os << norm_hour << "rub/hour";
		os.width(8);
		os << right;
		os << salary << "rub";
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os.width(16);
		os << left;
		os << post << "|";
		os.width(8);
		os << right;
		os << experience << "y|";
		os.width(8);
		os << right;
		os << time_worked << "hour|";
		os.width(8);
		os << right;
		os << norm_hour << "rub/hour|";
		os.width(10);
		os << right;
		os << salary << "rub|";
		return os;
	}
	ifstream& input(ifstream& is)
	{
		Human::input(is);
		std::getline(is, post, '|');
		string xp_buffer;
		std::getline(is, xp_buffer, '|');
		experience = std::stod(xp_buffer);
		string time_worked_buffer;
		std::getline(is, time_worked_buffer, '|');
		this->time_worked = std::stod(time_worked_buffer);
		string norm_hour_buffer;
		std::getline(is, norm_hour_buffer, '|');
		this->norm_hour = std::stod(norm_hour_buffer);
		string salary_buffer;
		std::getline(is, salary_buffer, '|');
		this->salary = std::stod(salary_buffer);
		return is;
	}
};

void SaveToFile(Human* group[], const int size, const string& filename);
void Print(Human* group[], const int size);
Human** LoadFromFile(const std::string& filename);
Human* HumanFactory(const std::string& human_type);

#define DEPARTAMENT

void main()
{
	setlocale(LC_ALL, "");
#ifdef DEPARTAMENT
	//Generalisation:
	Human* group[] =
	{
		new Accounting("Pinkman", "Jessie", 22, "Accountant", 12, 15000),
		new Logistics("White", "Walter", 50, "Driver", 15, 180, 1000),
		new Accounting("Diaz", "Ricardo", 55, "Chief accountant", 34, 30000),
		new Logistics("Eistein", "Albert", 54, "Driver", 25, 180, 1500),
	};
	
	//Specialisation
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n-----------------------------\n";
		cout << *group[i] << endl;
	}
	cout << "\n-----------------------------\n";

	string filename = "deparatment.txt";
	SaveToFile(group, sizeof(group) / sizeof(group[0]), "deparatment.txt");

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}

#endif // DEPARTAMENT

	//Human** group = LoadFromFile("deparatment.txt");
	//Print(group, 6);
}

void SaveToFile(Human* group[], const int size, const string& filename)
{
	ofstream fout(filename);
	for (int i = 0; i < size; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
}
void Print(Human* group[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *group[i] << endl;
	}
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
			cout << fin.tellg() << endl;
			n++;
		}
		Human** group = new Human * [n] {};
		fin.clear();
		fin.seekg(ios::beg, 0);
		cout << fin.tellg() << endl;
		string human_type;
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, human_type, '|');
			group[i] = HumanFactory(human_type);
			fin >> *group[i];
		}
		fin.close();
		return group;
	}
	else
	{
		cerr << "Error: File not found!" << endl;
	}
	return nullptr;
}
Human* HumanFactory(const std::string& human_type)
{
	if (human_type.find("class Accounting") != string::npos) return new Accounting("last_name", "first_name", 0, "spec", 0, 0);
	if (human_type.find("class Logistics") != string::npos) return new Logistics("last_name", "first_name", 0, "spec", 0, 0, 0);
	return nullptr;
}