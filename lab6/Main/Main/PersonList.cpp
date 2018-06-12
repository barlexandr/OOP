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
	} while (sexOfPerson != 1 && sexOfPerson != 2); //Проверка допустимости значения

	sex = (Sex)sexOfPerson;

	do
	{
		cout << "Enter the person age, pls (0 - 120):";
		cin >> age;
	} while (age < 0 || age > 120); //Проверка корректности возраста

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

//Добавление записи в конец
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

//Добавление человека с рандомными данными
void PersonList::RandomPersonAdd()
{
	string name[] { "Mark", "Jack", "Ken", "Anton", "John", "Jorj", "Den", "Bill",
		"Alexa", "Amy", "Grace", "Jane", "Jasmine", "Ella", "Clara" };
	string surname[] {"Bishep", "Macey", "Alsopp", "Fisher", "Farrell", "Taft", "Porter",
		"Finch", "Waller", "Sherlok", "Roberts", "Waller", "Hawkins", "Wood", "Turner"};

	int randomNameIndex = rand() % 14; //Случайный индекс для имени
	int randomSurnameIndex = rand() % 14; //Случайный индекс для фамилии

	string NAME = name[randomNameIndex];
	//size_t sizeName = strlen(name[randomNameIndex].c_str()) + 1;
	//char *charName = new char[sizeName + 1];
	//strcpy_s(charName, sizeName, NAME.c_str());

	string SURNAME = surname[randomSurnameIndex];
	//size_t sizeSurname = strlen(surname[randomSurnameIndex].c_str()) + 1;
	//char *charSurname = new char[sizeSurname + 1];
	//strcpy_s(charSurname, sizeSurname, SURNAME.c_str());


	//Person *randPerson = MakeRandomPerson(charName, charSurname, randomNameIndex);
	Person *randPerson = MakeRandomPerson(NAME, SURNAME, randomNameIndex);

	//delete[] charName; charName = nullptr;
	//delete[] charSurname; charSurname = nullptr;

	Add(new Person(*randPerson));

	delete randPerson;
}

//Создание человека с рандомными данными
Person *PersonList::MakeRandomPerson(string Name, string Surname, int randomNameIndex)
{
	Person *randPerson = new Person;

	//Заполнение данными
	//int i(0);
	//for (; i < NAMELENGTH && name[i]; ++i)
	//	randPerson->name[i] = name[i];
	//randPerson->name[i] = '\0';
	randPerson->SetName(Name);
	randPerson->SetSurname(Surname);

	//int j(0);
	//for (; j < SURNAMELENGTH && surname[j]; ++j)
	//	randPerson->surname[j] = surname[j];
	//randPerson->surname[j] = '\0';

	int years = rand() % 121 + 0;
	randPerson->SetAge(years);

	randPerson->SetSex((randomNameIndex > 7) ? female : male);

	return randPerson;
}

//Поиск человека по указанному индексу
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

//Возвращает индекс человека, если он есть в списке 
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

//Удаление элемента списка
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

//Удаление элемента списка по индексу
void PersonList::RemoveAt(int index)
{
	Person *person = Find(index);
	Remove(person);
}

//Очистка списка
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

string PersonList::OutputInformation()
{
	string information;

	PersonListItem *item = _head;

	while (item)
	{
		if (item->GetValue()->GetAge() > 17)
		{
			information.append(item->GetValue()->GetDiscription());
				item = item->next;
		}
	
	}

	if (!_head)
	{
		cout << "Head = NULL \t Tail = NULL " << endl;
	}






	return information;
}

//Вывести запись
void PersonList::OutputNote(PersonListItem list, int count)
{
	cout << "Note №" << count << endl;
	cout << "Name: " << list.GetValue()->GetName() << endl;
	cout << "Surmane: " << list.GetValue()->GetSurname() << endl;
	cout << "Sex: ";

	list.GetValue()->GetSex() == male
		? cout << "Male"
		: cout << "Female";

	cout << "Age: " << list.GetValue()->GetAge() << endl;

	//if (list.GetValue()->GetAge() > 17)
	//{
	//	cout << "This is an adult." << endl;
	//	list.GetValue() - ;
	//}

	cout << endl << endl;
}

//Вывести список
void PersonList::OutputList()
{
	cout << endl;
	PersonListItem *item = _head;
	int i(1);
	while (item)
	{
		OutputNote(*item, i);
		item = item->next;
		++i;
	}

	if (!_head)
	{
		cout << "Head = NULL \t Tail = NULL " << endl;
	}
}