#pragma once
#include "Person.h"

class Child : public Person
{
public:
	Person *Mother = nullptr;
	Person *Father = nullptr;
	string school;

	virtual string GetDiscription();	//�������� ���������� � �������
	virtual void SetAge(unsigned int Age);
	virtual unsigned int GetAge();

	static Child *RandomChild();	//�������� ���������� �������
	static Person *RandomFather(string surnameFather);	//�������� ���������� ���� � ������ ��������
	static Person *RandomMother(string surnameMother);	//�������� ��������� ������ � ������ ��������

	Child(string Name, string Surname, unsigned int Age, enum Sex Sex);
	Child();
	~Child();
};

