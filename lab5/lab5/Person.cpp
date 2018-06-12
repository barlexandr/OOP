#include "stdafx.h"
#include "Person.h"

Person::Person()
{ }

Person::Person(char Name[], char Surname[], int Age, Sex Sex)
{
	SetName(Name);
	SetSurname(Surname);
	SetAge(Age);
	SetSex(Sex);
}

void Person::SetName(char Name[])
{
	int i(0);
	for (; i < NAMELENGTH && Name[i]; ++i)
		name[i] = Name[i];

	name[i] = '\0';
}

void Person::SetSurname(char Surname[])
{
	int i(0);
	for (; i < SURNAMELENGTH && Surname[i]; ++i)
		surname[i] = Surname[i];

	surname[i] = '\0';
}

void Person::SetAge(int Age)
{
	age = Age;
}

void Person::SetSex(Sex Sex)
{
	sex = Sex;
}