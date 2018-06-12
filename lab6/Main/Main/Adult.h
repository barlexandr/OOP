#pragma once
#include "Person.h"

class Adult : public Person
{
private:
	string workPlase;
public:
	Person *MarriedOn = nullptr;

	virtual string GetDiscription();	//�������� ���������� � ��������
	virtual void SetAge(unsigned int Age);
	virtual unsigned int GetAge();

	void SetWorkPlase(string WorkPlase);
	string GetWorkPlase();	

	static Adult* RandomAdult();		//�������� ���������� ���������

	Adult(string Name, string Surname, unsigned int Age, enum Sex Sex);
	Adult();
	~Adult();
};

