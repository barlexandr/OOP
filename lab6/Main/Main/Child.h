#pragma once
#include "Person.h"

class Child : public Person
{
public:
	Person *Mother = nullptr;
	Person *Father = nullptr;
	string school;

	virtual string GetDiscription();	//Получить информацию о ребенке
	virtual void SetAge(unsigned int Age);
	virtual unsigned int GetAge();

	static Child *RandomChild();	//Создание рандомного ребенка
	static Person *RandomFather(string surnameFather);	//Создание рандомного отца с данной фамилией
	static Person *RandomMother(string surnameMother);	//Создание рандомной матери с данной фамилией

	Child(string Name, string Surname, unsigned int Age, enum Sex Sex);
	Child();
	~Child();
};

