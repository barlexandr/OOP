#include "stdafx.h"
#include "Adult.h"

//Получить информацию о взрослом
string Adult::GetDiscription()
{
	string dataLineAdult = Person::GetDiscription();
	
	if (MarriedOn == nullptr)
		dataLineAdult.append("Family status: ")
		.append("Single.\n");
	else
	{
		dataLineAdult.append("Family status: ")
			.append("Married on ")
			.append(MarriedOn->GetInfoForNameSurname())
			.append(".\n");
	}

	if (workPlase == "Unemployee")
		dataLineAdult.append("Unemployee.");
	else
	{
		dataLineAdult.append("Plase of work: ")
			.append(workPlase)
			.append(".");
	}
	return dataLineAdult;
}

void Adult::SetAge(unsigned int Age)
{
	bool flag = true;
	while (flag)
	{
		if (Age > 17)
		{
			Person::SetAge(Age);
			flag = false;
		}
		else
			printf("This is not an adult. This is a child.\n Pls, enter an age greater then 18.\n");
	}
}

unsigned int Adult::GetAge()
{
	return Person::GetAge();
}

void Adult::SetWorkPlase(string WorkPlase)
{
	workPlase = WorkPlase;
}

string Adult::GetWorkPlase()
{
	return workPlase;
}

//Создание рандомного взрослого
Adult* Adult::RandomAdult()
{
	string name[] { "Mark", "Jack", "Ken", "Anton", "John", "Jorj", "Den", "Bill",
		"Alexa", "Amy", "Grace", "Jane", "Jasmine", "Ella", "Clara" };
	string surname[] {"Bishep", "Macey", "Alsopp", "Fisher", "Farrell", "Taft", "Porter",
		"Finch", "Waller", "Sherlok", "Roberts", "Waller", "Hawkins", "Wood", "Turner"};
	string work[] {"Microsoft", "Google", "Apple", "Samsung", "Oracle", "IBM", "Cisco",
		"Adobe", "Workday", "Yandex", "Amazom"};

	int randomNameIndex = rand() % 14;		//Случайный индекс для имени
	int randomSurnameIndex = rand() % 14;	//Случайный индекс для фамилии
	int randomWorkIndex = rand() % 10;		//Случайный индекс для места работы

	string nameAdult = name[randomNameIndex];
	string surnameAdult = surname[randomSurnameIndex];
	string workAdult = work[randomWorkIndex];
	unsigned int yearsAdult = rand() % 83 + 18;

	Adult *adult = new Adult;

	adult->SetName(nameAdult);
	adult->SetSurname(surnameAdult);
	adult->SetAge(yearsAdult);
	adult->SetSex((randomNameIndex > 7) ? female : male);

	int working = rand() % 2 + 1;	//1- работает, 2- безработный.
	if (working == 1)
		adult->SetWorkPlase(workAdult);
	else if (working == 2)
		adult->SetWorkPlase("Unemployee");
	
	int married = rand() % 2 + 1;	//1- женат, 2- не женат.
	if (married == 1)
	{
		if (adult->GetSex() == male)
		{
			Adult *adultWomen = new Adult;

			unsigned int womenRandomIndex = rand() % 8 + 8;
			string nameWomen = name[womenRandomIndex];
			unsigned yearsWomen = rand() % 83 + 18;

			adultWomen->SetName(nameWomen);
			adultWomen->SetSurname(surnameAdult);
			adultWomen->SetAge(yearsWomen);
			adultWomen->SetSex(female);
			adultWomen->MarriedOn = adult;

			adult->MarriedOn = adultWomen;
		}
		else if (adult->GetSex() == female)
		{
			Adult *adultMen = new Adult;

			unsigned int menRandomIndex = rand() % 8 + 0;
			string nameMen = name[menRandomIndex];
			unsigned yearsMen = rand() % 83 + 18;

			adultMen->SetName(nameMen);
			adultMen->SetSurname(surnameAdult);
			adultMen->SetAge(yearsMen);
			adultMen->SetSex(male);
			adultMen->MarriedOn = adult;

			adult->MarriedOn = adultMen;
		}
	}
	else
		adult->MarriedOn = nullptr;
	
	return adult;
}

//Используем делегирующий конструктор
Adult::Adult(string Name, string Surname, unsigned int Age, enum Sex Sex) : Person(Name, Surname, Age, Sex)
{
}

Adult::Adult()
{
}

Adult::~Adult()
{
	if (MarriedOn != nullptr)
	{
		delete MarriedOn;
		MarriedOn = nullptr;
	}
}
