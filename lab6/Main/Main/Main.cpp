#include "stdafx.h"
#include "PersonList.h"
#include <Windows.h>//��� ����������� �������� ���� ������

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	try
	{
	/*��������� �����������*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		PersonList *list = new PersonList;
		const int countOfPersonAdded = 7;

		for (int i(0); i < countOfPersonAdded; ++i)
		{
			int whomToAdd = rand() % 2 + 1;// 1- �������� �������, 2- ���������.

			if (whomToAdd == 1)
			{
				Child *child = Child::RandomChild();
				list->Add(child);
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
				cout << "\t\tNote � " << i + 1 << ":" << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
				cout << child->GetDiscription() << endl;
			}

			else if (whomToAdd == 2)
			{
				Adult *adult = Adult::RandomAdult();
				list->Add(adult);
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
				cout << "\t\tNote � " << i + 1 << ":" << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
				cout << adult->GetDiscription() << endl;
			}
		}	
	}
	catch (...)
	{
		puts("ERORCYKA");
	}
	//list->

	system("pause");

}

