#include "stdafx.h"
#include "PersonList.h"

PersonList::PersonList()
{
	_count = 0;
	_head = nullptr;
	_tail = nullptr;
}

PersonList::~PersonList()
{
	Clear();
}

PersonList::PersonListItem::PersonListItem()
{
	_value = nullptr;
	next = nullptr;
	previous = nullptr;
}

PersonList::PersonListItem::PersonListItem(Person* person)
{
	_value = person;
	next = nullptr;
	previous = nullptr;
}

Person* PersonList::PersonListItem::GetValue()
{
	return _value;
}

void PersonList::ReadingPerson()
{
	string name;
	string surname;
	unsigned int age;
	Sex sex;

	cout << endl << "Enter the person name, pls:";
	cin >> name;

	cout << endl << "Enter the person surname, pls:";
	cin >> surname;

	int sexOfPerson;
	do
	{
		cout << ("Enter the person sex, pls (male = 1,female = 2): ");
		cin >> sexOfPerson;
	} while (sexOfPerson != 1 && sexOfPerson != 2); //�������� ������������ ��������

	sex = (Sex)sexOfPerson;

	do
	{
		cout << "Enter the person age, pls (0 - 120):";
		cin >> age;
	} while (age < 0 || age > 120); //�������� ������������ ��������

	Add(new Person(name, surname, age, sex));
}

int PersonList::GetCount()
{
	return _count;
}

void PersonList::SetCount(int count)
{
	_count = count;
}

//���������� ������ � �����
void PersonList::Add(Person *person)
{
	PersonListItem *item = new PersonListItem(person);

	if (_head)
	{
		item->previous = _tail;
		_tail->next = item;
		_tail = item;
	}
	else
		_head = _tail = item;

	SetCount(GetCount() + 1);
}

//���������� �������� � ���������� �������
void PersonList::RandomPersonAdd()
{
	string name[] { "Mark", "Jack", "Ken", "Anton", "John", "Jorj", "Den", "Bill",
		"Alexa", "Amy", "Grace", "Jane", "Jasmine", "Ella", "Clara" };
	string surname[] {"Bishep", "Macey", "Alsopp", "Fisher", "Farrell", "Taft", "Porter",
		"Finch", "Waller", "Sherlok", "Roberts", "Waller", "Hawkins", "Wood", "Turner"};

	int randomNameIndex = rand() % 14; //��������� ������ ��� �����
	int randomSurnameIndex = rand() % 14; //��������� ������ ��� �������

	string NAME = name[randomNameIndex];
	string SURNAME = surname[randomSurnameIndex];

	Person *randPerson = MakeRandomPerson(NAME, SURNAME, randomNameIndex);

	Add(new Person(*randPerson));

	delete randPerson;
}

//�������� �������� � ���������� �������
Person *PersonList::MakeRandomPerson(string Name, string Surname, int randomNameIndex)
{
	Person *randPerson = new Person;

	//���������� �������
	randPerson->SetName(Name);
	randPerson->SetSurname(Surname);

	int years = rand() % 121 + 0;
	randPerson->SetAge(years);

	randPerson->SetSex((randomNameIndex > 7) ? female : male);

	return randPerson;
}

//����� �������� �� ���������� �������
Person* PersonList::Find(int index)
{
	if (index < 0)
		return nullptr;

	int i(0);
	PersonListItem* item = _head;
	while (i < index)
	{
		if (item == nullptr)
			return nullptr;

		item = item->next;
		++i;
	}
	return item->GetValue();
}

//���������� ������ ��������, ���� �� ���� � ������ 
int PersonList::IndexOf(Person *person)
{
	PersonListItem *item = _head;
	int index(0);
	while (item)
	{
		if ((item->GetValue()->GetName()) == (person->GetName())
			&& (item->GetValue()->GetAge() == (person->GetAge()))
			&& (item->GetValue()->GetSex() == (person->GetSex()))
			&& ((item->GetValue()->GetSurname()) == (person->GetSurname())))
		{
			return index;
		}
		++index;
		item = item->next;
	}
	return -1;
}

//�������� �������� ������
void PersonList::Remove(Person *person)
{
	PersonListItem *item = _head;
	while (item)
	{
		if ((item->GetValue()->GetName()) == (person->GetName())
			&& (item->GetValue()->GetAge() == (person->GetAge()))
			&& (item->GetValue()->GetSex() == (person->GetSex()))
			&& ((item->GetValue()->GetSurname()) == (person->GetSurname())))
		{
			if (_head == item)
			{
				if (item->next)
				{
					_head = nullptr;
					_tail = nullptr;
					SetCount(GetCount() - 1);
					break;
				}

				_head->next->previous = nullptr;
				_head = _head->next;
				SetCount(GetCount() - 1);
				break;
			}

			if (_tail == item)
			{
				_tail->previous->next = nullptr;
				_tail = _tail->previous;
				SetCount(GetCount() - 1);
				break;
			}

			if (_head != item && _tail != item)
			{
				item->previous->next = item->next;
				item->next->previous = item->previous;
				SetCount(GetCount() - 1);
				break;
			}
		}
		item = item->next;
	}
}

//�������� �������� ������ �� �������
void PersonList::RemoveAt(int index)
{
	Person *person = Find(index);
	Remove(person);
}

//������� ������
void PersonList::Clear()
{
	PersonListItem *listPointer = _head;
	if (listPointer)
	{
		while (listPointer->next)
		{
			listPointer = listPointer->next;

			delete listPointer->previous;
			listPointer->previous = nullptr;
		}
		delete listPointer;
		listPointer = nullptr;
	}
	_head = nullptr;
	_tail = nullptr;
	SetCount(0);
}