#define NAMELENGTH 20
#define SURNAMELENGTH 30

enum Sex
{
	male = 1,
	female
};

class Person
{
public:
	char name[NAMELENGTH];
	char surname[SURNAMELENGTH];
	int age;
	Sex sex;

	Person();
	Person(char Name[], char Surname[], int Age, Sex Sex);

	void SetName(char Name[]);
	void SetSurname(char Surname[]);
	void SetAge(int Age);
	void SetSex(Sex Sex);
};