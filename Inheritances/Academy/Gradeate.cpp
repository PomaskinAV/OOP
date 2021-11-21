#include"Graduate.h"
#include"Student.h"

const string& Graduate::get_diploma()const
{
	return diploma;
}
void Graduate::set_diploma(const string& diploma)
{
	this->diploma = diploma;
}
// Constructors:
Graduate::Graduate
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& group, double rating, const string& diploma
) :Student(last_name, first_name, age, speciality, group, rating)// Делигируем конструктор
{
	set_diploma(diploma);
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}
// Methods:
void Graduate::print()const
{
	Student::print();
	cout << "Тема дипломной работы работы: " << diploma << endl;
}