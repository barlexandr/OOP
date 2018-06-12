#pragma once
#include "stdafx.h"

enum Sex
{
	male = 1,
	female
};

class Person
{
protected:
	string name;
	string surname;
	unsigned int age;
	Sex sex;

public:
	void SetName(string Name);
	void SetSurname(string Surname);
	virtual void SetAge(unsigned int Age);
	void SetSex(Sex Sex);

	string GetName();
	string GetSurname();
	virtual unsigned int GetAge();
	Sex GetSex();

	virtual string GetDiscription();	//получить информацию о человеке
	string GetInfoForNameSurname();		//получить имя и фамилию человека

	~Person();
	Person();
	Person(string Name, string Surname, unsigned int Age, Sex Sex);
};
