#include "stdafx.h"
#include "Child.h"

//Получить информацию о ребенке
string Child::GetDiscription()
{
	string child = Person::GetDiscription();

	if (Mother == nullptr && Father == nullptr)
		child.append("Parents are not specified.\n");
	else if (Mother == nullptr)
	{
		child.append("Father is ")
			.append(Father->GetInfoForNameSurname())
			.append(".\n");
	}
	else if (Father == nullptr)
	{
		child.append("Mother is ")
			.append(Mother->GetInfoForNameSurname())
			.append(".\n");
	}
	if (Mother != nullptr && Father != nullptr)
	{
		child.append("Parents are: ")
			.append(" mother is ")
			.append(Mother->GetInfoForNameSurname())
			.append(", father is ")
			.append(Father->GetInfoForNameSurname())
			.append(".\n");
	}
	
	if (school.length() < 0)
		child.append("Does not go to school/kindergarten.");
	else
	{
		child.append("Goes to ")
			.append(school)
			.append(".");
	}
	return child;
}

void Child::SetAge(unsigned int Age)
{
	bool flag = true;
	while (flag)
	{
		if (Age < 18)
		{
			Person::SetAge(Age);
			flag = false;
		}
		else 
			printf("This is not a child. This is an adult.\n Pls, enter the age below 18.\n");
	}
}
unsigned int Child::GetAge()
{
	return Person::GetAge();
}

//Создание отца с фамилией как у ребенка
Person* Child::RandomFather(string surnameFather)
{
	string name[] { "Mark", "Jack", "Ken", "Anton", "John", "Jorj", "Den", "Bill"};
	unsigned int fatherRandomIndex = rand() % 8 + 0;
	string nameFather = name[fatherRandomIndex];
	unsigned int ageFather = rand() % 83 + 18;

	Person *father = new Person;
	father->SetName(nameFather);
	father->SetSurname(surnameFather);
	father->SetAge(ageFather);
	father->SetSex(male);

	return father;
}

//Создание матери с фамилией как у ребенка
Person* Child::RandomMother(string surnameMather)
{
	string name[] {"Alexa", "Amy", "Grace", "Jane", "Jasmine", "Ella", "Clara" };
	unsigned int motherRandomIndex = rand() % 7 + 0;
	string nameMother = name[motherRandomIndex];
	unsigned int ageMother = rand() % 83 + 18;

	Person *mother = new Person;
	mother->SetName(nameMother);
	mother->SetSurname(surnameMather);
	mother->SetAge(ageMother);
	mother->SetSex(female);

	return mother;
}

//Создание рандомного ребенка
Child* Child::RandomChild()
{
	string name[] { "Mark", "Jack", "Ken", "Anton", "John", "Jorj", "Den", "Bill",
		"Alexa", "Amy", "Grace", "Jane", "Jasmine", "Ella", "Clara" };
	string surname[] {"Bishep", "Macey", "Alsopp", "Fisher", "Farrell", "Taft", "Porter",
		"Finch", "Waller", "Sherlok", "Roberts", "Waller", "Hawkins", "Wood", "Turner"};
	
	int randomNameIndex = rand() % 14;		//Случайный индекс для имени
	int randomSurnameIndex = rand() % 14;	//Случайный индекс для фамилии

	string nameChild = name[randomNameIndex];
	string surnameChild = surname[randomSurnameIndex];
	unsigned int yearsAdult = rand() % 16 + 2;

	Child* child = new Child;
	child->SetName(nameChild);
	child->SetSurname(surnameChild);
	child->SetAge(yearsAdult);
	child->SetSex((randomNameIndex > 7) ? female : male);

	int parents = rand() % 4 + 1; //1- есть родители, 2- нет мамы, 3- нет папы, 4- нет обоих.
	if (parents == 1)
	{
		Person *father = RandomFather(surnameChild);
		child->Father = father;

		Person *mother = RandomMother(surnameChild);
		child->Mother = mother;
	}
	else if (parents == 2)
	{
		Person *father = RandomFather(surnameChild);

		child->Father = father;
		child->Mother = nullptr;
	}
	else if (parents == 3)
	{
		Person *mother = RandomMother(surnameChild);

		child->Mother = mother;
		child->Father = nullptr;
	}
	else if (parents == 4)
	{
		child->Father = nullptr;
		child->Mother = nullptr;
	}

	if (yearsAdult < 8)
	{
		string kindergarten[] {"Kindergarten №2", "Kindergarten №7", "Kindergarten №3", "Kindergarten №2",
			"Kindergarten at luceum №3", "Kindergarten at school №76", "Kindergarten №9"};

		int randomKindergartenIndex = rand() % 6; //Случайный индекс для детского сада
		string kindergartenChild = kindergarten[randomKindergartenIndex];
		child->school = kindergartenChild;
	}
	else if (yearsAdult > 7)
	{
		string school[] {"Luceum №3", "Gorky school", "School named after Lomonosov", "Luceum TGY",
			"Gymnasium №7", "School №76", "School №35"};

		int randomSchoolIndex = rand() % 6;		//Случайный индекс для школы
		string schoolChild = school[randomSchoolIndex];
		child->school = schoolChild;
	}
	return child;
}



Child::Child(string Name, string Surname, unsigned int Age, enum Sex Sex) : Person(Name, Surname, Age, Sex)
{
}

Child::Child()
{
}

Child::~Child()
{
	if (Mother != nullptr)
		delete Mother;
	if (Father != nullptr)
		delete Father;
}
