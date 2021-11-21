#pragma once
#include"Human.h"
#include"Student.h"
class Graduate :public Student
{
	string diploma;
public:
	const string& get_diploma()const;
	void set_diploma(const string& diploma);
	// Constructors:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating, const string& diploma
	);
	~Graduate();
	// Methods:
	void print()const;
};