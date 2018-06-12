#pragma once
#include "Person.h"

class Adult : public Person
{
private:
	string workPlase;
public:
	Person *MarriedOn = nullptr;

	virtual string GetDiscription();	//получить информацию о человеке
	virtual void SetAge(unsigned int Age);
	virtual unsigned int GetAge();

	void SetWorkPlase(string WorkPlase);
	string GetWorkPlase();	

	static Adult* RandomAdult();		//Создание рандомного взрослого

	Adult(string Name, string Surname, unsigned int Age, enum Sex Sex);
	Adult();
	~Adult();
};

