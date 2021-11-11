#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
 


using namespace std;

//Functia care realizeaza Loading ... cu flush pe puncte 
void flash() {
	cout << "Loading";
	cout.flush();
	int j = 0;
	for (int j=0;j<2;j++) {
		for (int i = 0; i < 3; i++) {
			cout << ".";
			cout.flush();
			Sleep(250);
		}
		cout << "\b\b\b   \b\b\b";
	}	
	cout << endl;
	system("CLS");//Clear CMD
}

bool check(string a, string b)
{
	fstream fisier("Conturi.txt");
	int ok = 0;
	string linie;
	while (getline(fisier, linie))
	{
		size_t p1 = linie.find(a);
		size_t p2 = linie.find(b);
		if (p1 != string::npos && p2 != string::npos)
			ok = 1;
	}
	if (ok == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_username(string user)
{
	fstream fisier("Conturi.txt");
	int ok = 0;
	string linie;
	while (getline(fisier, linie))
	{
		size_t p1 = linie.find(user);
		if (p1 != string::npos)
			ok = 1;
	}
	if (ok == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_parola(string parola)
{
	int i = 0;
	int j = 0;
	int n = size(parola);
	int ok = 0;
	int ok2=0;
	char vect[] = { '*','@','%','!','@','#','&' };
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (parola[i] == vect[j])
			{
				ok = 1;
			}
		}
		if (ok == 1)
		{
			ok2 = 1;
		}

	}
	if (ok2 == 0)
	{
		cout << "	Parola nu contine una din caracterele speciale ! \n Pentru a putea fi mai greu de ghicit trebuie sa le foloseste \n Succes :) \n Noua parola este : ";
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	string user, parola, nume;
	int optiune;

	Sleep(300);
	
	fstream fisier;
	fisier.open("Conturi.txt", fstream::app);
	do {
		cout << "	***********************\n" << endl;

		cout << "	1.Register \n	2.Login " << endl;
		cout << "\n	***********************\n" << endl;

		Sleep(300);


		cout << "	Alege o optiune : ";
		cin >> optiune;
		switch (optiune)
		{
		case 1:
		{
			fstream fisier("Conturi.txt");

			flash();

			cout << "\n	Introdu Numele : ";
			cin >> nume;

			cout << "\n	Introdu Username-ul :  ";
			cin >> user;
			if (check_username(user))
			{
				cout << "	User name-ul este deja luat ! \n Incearca altul ! \n";
				cout << "	Introdu Username-ul :";
				cin >> user;
			}

			cout << "	Parola trebuie sa contina :\n	*Litere mici si mari \n	*Cifre \n	*Litere speciale ca : *,@,%,!,@,%...etc \n	*NU TREBUIE SA CONTINA SPATIU " << endl;;

			Sleep(700);

			cout << "\n Introdu parola : ";
			cin >> parola;

			while (check_parola(parola) == true)
			{
				cin >> parola;
			}
			fisier << "	*********************************\n" << endl;
			fisier << "	Contul lui :" << nume << endl;
			fisier << "	Username : " << user << endl;
			fisier << "	Parola : " << parola << endl;
			fisier << "\n	*********************************" << endl;
			cout << endl;

			flash();

			cout << "	Te-ai inregistrat cu succes !\n ";

			break;
		}
		case 2:
		{
			cout << " Username : ";
			cin >> user;
			cout << " Parola : ";
			cin >> parola;

			flash();

			if (check(user, parola) == true)
			{
				cout << "	Te-ai logat cu succes !" << endl;
			}
			else
			{
				cout << "	User sau parola sunt gresite !" << endl;
			}

			break;
		}
		default:

			break;
		}
	} while (optiune < 3);
	return 0;
}


	

