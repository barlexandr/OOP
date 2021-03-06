#pragma once
#include "Person.h"
//#include <random>

class PersonList
{
private: 
	class PersonListItem
	{
	private:
		Person *_value;
	public:
		PersonListItem* next;
		PersonListItem* previous;

		PersonListItem();
		PersonListItem(Person* person);
		Person* GetValue();
	};

	PersonListItem* _head; //��������� �� ������ ������ 
	PersonListItem* _tail; //��������� �� ����� ������
	int _count;    //���������� ��������� � ������ 

public: 
	PersonList();
	~PersonList();

	void Add(Person *person);  //�������� �������� � ������ 
	Person* Find(int index);  //����� �������� �� ���������� ������� 
	int IndexOf(Person *person);  //������� ������ ��������, ���� �� ���� � ������ 
	void Remove(Person *person);  //������� �������� �� ������ 
	void RemoveAt(int index);  //������� �������� �� ������ �� ������� 
	void Clear();    //�������� ������ 
	int GetCount();   //�������� ���������� ��������� 
	void SetCount(int count); //���������� ���������� ���������
	void ReadingPerson(); //����������� ������
	void RandomPersonAdd(); //���������� �������� � ���������� ������� 
	Person* MakeRandomPerson(char* name, char* surname, int randomNameIndex); //�������� �������� � ���������� ������� 
	void OutputNote(PersonListItem list, int count); //������� ������
	void OutputList(); //������� ��� ������ �� �����
};
