#include "stdafx.h"
#include "Person.h"

Person::Person(string Name, string Surname, unsigned int Age, Sex Sex)
{
	SetName(Name);
	SetSurname(Surname);
	SetAge(Age);
	SetSex(Sex);
}

void Person::SetName(string Name)
{
	name = Name;
}
void Person::SetSurname(string Surname)
{
	surname = Surname;
}

void Person::SetAge(unsigned int Age)
{
		age = Age;
}
void Person::SetSex(Sex Sex)
{
	sex = Sex;
}

string Person::GetName()
{
	return name;
}

string Person::GetSurname()
{
	return surname;
}

unsigned int Person::GetAge()
{
	return age;
}

Sex Person::GetSex()
{
	return sex;
}

//Получить информацию о человеке
string Person::GetDiscription()
{
	string dataLine;
	dataLine.append(name)
		.append(" ")
		.append(surname)
		.append(", ")
		.append(to_string(age))
		.append(" years old, ");
	if (sex == male)
		dataLine.append("male.\n");
	else
		dataLine.append("female.").append("\n");

	return dataLine;
}

//Получить имя и фамилию человека
string Person::GetInfoForNameSurname()
{
	string spouse;
	spouse.append(name)
		.append(" ")
		.append(surname);
	return spouse;
}

Person::Person()
{
}

Person::~Person()
{
}