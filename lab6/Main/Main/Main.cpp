#include "stdafx.h"
#include "PersonList.h"
#include <Windows.h>//Для возможности изменять цвет текста

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	try
	{
		/*Получение дескриптора*/
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		PersonList *list = new PersonList;
		const int countOfPersonAdded = 7;

		for (int i(0); i < countOfPersonAdded; ++i)
		{
			int whomToAdd = rand() % 2 + 1;// 1- добавить ребенка, 2- взрослого.

			if (whomToAdd == 1)
			{
				Child *child = Child::RandomChild();
				list->Add(child);
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
				cout << "\t\tNote № " << i + 1 << ":" << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
				cout << child->GetDiscription() << endl;
			}

			else if (whomToAdd == 2)
			{
				Adult *adult = Adult::RandomAdult();
				list->Add(adult);
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
				cout << "\t\tNote № " << i + 1 << ":" << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
				cout << adult->GetDiscription() << endl;
			}
		}	

		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
		cout << "\n\nProgrammatically define the type 4 person in our list." << endl;
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
		Person *find = list->Find(3);
		
		if (find->GetAge() < 18)
		{
			cout << "This is a child." << endl;
			//Child *child = (Child*)find;
			//cout << child->GetDiscription() << endl;
			cout << find->GetDiscription() << endl;//Полиморфизм
		}
		else
		{
			cout << "This is an adult." << endl;
			//Adult *adult = (Adult*)find;
			//cout << adult->GetDiscription() << endl;
			cout << find->GetDiscription() << endl; //полиморфизм
		}


	}
	catch (...)
	{
		puts("EROR");
	}

	system("pause");
}

