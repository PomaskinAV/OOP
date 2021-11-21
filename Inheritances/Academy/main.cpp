#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

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

		//Specialisation
		for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
		{
			cout << "\n-----------------------------\n";
			group[i]->print();
		}
		cout << "\n-----------------------------\n";

		for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
		{
			delete[] group[i];
		}
	}