#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;


struct stCompte {
	string first_name;
	string last_name;
	string email;
	string password;
	int carte_cin;
	float money;
	string message;
};
struct stBanque {
	stCompte compte;
};
void Space()
{
	cout << "\t\t------------------------------------\n";
	cout << "\t\t*---\t\tBANK\t\t---*\n";
	cout << "\t\t------------------------------------\n";
	cout << "\t\t*---\t\t\t\t---*\n";
	cout << "\t\t*--- 1- Space Admin\t\t---*\n";
	cout << "\t\t*--- 2- Space Client\t\t---*\n";
	cout << "\t\t*--- 0- Back\t\t\t---*\n";
	cout << "\t\t*---\t\t\t\t---*\n";
	cout << "\t\t------------------------------------\n";
}
/*ESPACE ADMIN*/
stCompte ReadCompteAdmin()
{
	stCompte compte;
	cout << "Adresse mail : "; cin >> compte.email;
	cout << "Password : "; cin >> compte.password;
	cout << "Cin : "; cin >> compte.carte_cin;

	while (compte.carte_cin < 10000000 || compte.carte_cin>99999999)
	{
		cout << "incorecct cin contains of 8 caracters......!\n";
		cout << "Please enter Correct Cin : "; cin >> compte.carte_cin;
	}
	cout << "Please Wait ...\n";
	Sleep(3000);
	return compte;
}
bool VerifCompteAdmin(int carte_cin,stCompte compte)
{
	if (compte.carte_cin == carte_cin)
	{
		system("color 2");
		cout << "opened Successfully\n";
		Sleep(3000);
		system("cls");
		return true;
	}
	else
	{
		cout << "Inccorect Account\n";
		
		return false;
	}
}
void PrintCompte(stCompte compte)
{
	cout << "First Name\t: " << compte.first_name << endl;
	cout << "Last Name\t: " << compte.last_name << endl;
	cout << "Email\t: " << compte.email << endl;
	cout << "Cin\t: " << compte.carte_cin << endl;
	cout << "Monney\t: " << compte.money<<" DT" << endl;
	cout << "Message\t : " << compte.message << endl;
}
void PrintAllComptes (stCompte C[],int nbr_c)
{
	for (int i = 0; i < nbr_c; i++)
	{
		cout << "\nAccount Number" << i + 1 << " :" << endl;
		PrintCompte(C[i]);
    }
}
void PrintChoiceCompte(stCompte C[], int nbr_c) {
	cout << "Please enter the Cin : \n";
	int carte_cin;
	cin >> carte_cin;
	for (int i = 0; i < nbr_c; i++)
	{
		if (C[i].carte_cin == carte_cin)
		{
			cout << "Please Wait ...\n";
			Sleep(3000);
			system("cls");
			PrintCompte(C[i]);
			break;
		}
	}
}
void MenuSpaceAdmin()
{
	cout << endl;
	cout << "\t\t\t\t(1) - Print Choose Account" << endl;
	cout << "\t\t\t\t(2) - Print All Accounts" << endl;
	cout << "\t\t\t\t(3) - Remove Account " << endl;
	cout << "\t\t\t\t(0) - Back " << endl;
}
/*ESPACE Client*/
int ReadNumberRange(string message, int from, int to)
{
	int number;
	cout << message << "\n>>";
	cin >> number;
	while (number <from || number>to)
	{
		cout << message << "\n>>";
		cin >> number;
	}
	return number;
}
void Welcome()
{
	cout << "\t\t\t*********************************************\n";
	cout << "\t\t\t*** Welcome in the best bank in the world ***" << endl;
	cout << "\t\t\t*********************************************\n";
	cout << "\t\t\t(1) - you have an account ?\n";
	cout << "\t\t\t(2) - do you want to create a new account?\n";
	cout << "\t\t\t(0) - Back \n";
	cout << "\t\t\t*********************************************\n\n";
}
void MenuSpaceClient()
{
	cout << "\t\t\t\t(1) - Account Statement" << endl;
	cout << "\t\t\t\t(2) - WithDraaw Monney" << endl;
	cout << "\t\t\t\t(3) - Add the monney" << endl;
	cout << "\t\t\t\t(4) - Clear the Account" << endl;
	cout << "\t\t\t\t(5) - Help " << endl;
	cout << "\t\t\t\t(0) - Back " << endl;
}
void AccountStatement(stCompte C[], int nbr_c, int carte_cin)
{
	for (int i = 0; i < nbr_c; i++)
	{
		if (C[i].carte_cin == carte_cin)
		{
			cout << "\n" << C[i].last_name << " " << C[i].first_name << " Have in You Account " << C[i].money << " DT \n\n";
			Sleep(6000);
			break;
		}
	}
}
void WithDrawMoney(stCompte C[], int nbr_c, int carte_cin) {
	int wd;
	for (int i = 0; i < nbr_c; i++)
	{
		if (C[i].carte_cin == carte_cin)
		{

			cout << "Howa much do you Want Draw Please (dt) : ";
			cin >> wd;
			while (wd < 0) {
				cout << "Negative number .????" << endl;
				cout << "Howa much do you Want Draw Please (dt) : ";
				cin >> wd;
			}
			if (wd == 0)
				cout << "\nKindding With You.!\n";
			else if (wd < 10)
				cout << "\nYou can not withdraw less than 10 DT\n";
			else
			{
				if (wd > C[i].money)
				{
					cout << "This Amount is More Than the Amount in Your Account...!\n";
				}
				else {
					cout << "Please Wait ...\n";
					Sleep(3000);
					vector <int>numbers;
					do {
						if (wd >= 50)
						{
							numbers.insert(numbers.begin(), 50);// add at Begining [10,5,6]
							wd -= 50;
						}
						else if (wd >= 20)
						{
							numbers.insert(numbers.begin(), 20);// add at Begining [10,5,6]
							wd -= 20;
						}
						else if (wd >= 10)
						{
							numbers.insert(numbers.begin(), 10);// add at Begining [10,5,6]
							wd -= 10;
						}
					} while (wd >= 10);
					int sumNumbers = 0;
					for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
						sumNumbers += *it;//parcourir vector and add element
						cout << *it << " + ";
					}
					C[i].money -= sumNumbers;
					cout << "\nOperation Accomplished Successfully\n\n";
					Sleep(4000);
				}
			}
		}
	}
}
void IncreaseMoney(stCompte C[], int nbr_c, int carte_cin) {
	int wd;
	for (int i = 0; i < nbr_c; i++)
	{
		if (C[i].carte_cin == carte_cin)
		{
			cout << "Howa much do you Want add Please (dt):  ";
			cin >> wd;
			while (wd < 0)
			{
				cout << "Negative number .????" << endl;
				cout << "Howa much do you Want add Please (dt):  ";
				cin >> wd;
			}
			if (wd == 0)
				cout << "\nKindding With You.!\n";
			else {
				C[i].money += wd;
				cout << "Please Wait ...\n";
				Sleep(3000);
				cout << "Operation Accomplished Successfully\n\n";
			}
		}
	}
}

void ClearAccount(stCompte C[], int& nbr_c, int carte_cin)
{
	for (int i = 0; i < nbr_c; i++)
	{
		if (C[i].carte_cin == carte_cin)
		{
			for (int j = i; j < nbr_c - 1; j++)
			{
				C[j] = C[j + 1];
			}
			nbr_c--;
			cout << "Please Wait ...\n";
			Sleep(3000);
			cout << "Operation Accomplished Successfully\n\n";
			break;
		}
	}
}
void connexion()
{
	for (int i = 1; i <= 100; i++)
	{
		cout << "Submission In Progress... \n";
		cout << i << "% :";
		for (int j = 1; j <= i; j++)
		{
			cout << '=';
		}
		cout << '>' << endl;
		if (i % 3 == 0)
			Sleep(60);
		else if (i % 5 == 0)
			Sleep(2000);
		else if (i == 99)
			Sleep(4000);
		else
			Sleep(300);
		if (i != 100)
			system("cls");
	}
}
void AddAccount(stCompte C[], int& nbr_c, stCompte compte)
{
	C[nbr_c] = compte;
	nbr_c++;
}
void Help(stCompte C[], int& nbr_c, int carte_cin)
{
	for (int i = 0; i < nbr_c; i++)
	{
		if (C[i].carte_cin == carte_cin)
		{
			cout << "Send a Message To The Bank :\n";
			cin.ignore(1, '\n');
			getline(cin,C[i].message);
			cout << "Please Wait ...\n";
			Sleep(3000);
			cout << "Operation Accomplished Successfully\n";
			break;
		}
	}
}
int ReadChoice()
{
	int number;
	cout << "Please enter the choice: ";
	cin >> number;
	while (number > 2 || number < 1) {
		cout << "Please enter the choice (1 or 2): ";
		cin >> number;
	}
	return number;
}
bool SearchExisteAccount(stCompte C[], int nbr_c, int carte_cin)
{
	for (int i = 0; i < nbr_c; i++)
	{
		if (C[i].carte_cin == carte_cin)
			return true;
	}
	return false;
}
stCompte ReadCompte(stCompte C[], int nbr_c)
{
	stCompte compte;
	cout << "Adresse mail : "; cin >> compte.email;
	cout << "Password : "; cin >> compte.password;
	cout << "Cin : "; cin >> compte.carte_cin;

	while (compte.carte_cin < 10000000 || compte.carte_cin>99999999)
	{
		cout << "incorecct cin contains of 8 caracters......!\n";
		cout << "Please enter Correct Cin : "; cin >> compte.carte_cin;
	}
	while (SearchExisteAccount(C, nbr_c, compte.carte_cin) == false)
	{
		cout << "This Cin does not exist......!\n";
		cout << "Please enter Correct Cin : "; cin >> compte.carte_cin;
	}
	cout << "Please Wait ...\n";
	Sleep(3000);
	system("color 2");
	cout << "opened Successfully\n";
	Sleep(3000);
	system("color 7");
	system("cls");
	return compte;
}
stCompte CreateCompte(stCompte C[], int nbr_c)
{
	cout << "PLease Enter your Inofrmation\n";
	stCompte compte;
	string np;
	compte.money = 0;
	cout << "Firsrt Name : "; cin >> compte.first_name;
	cout << "Last Name : "; cin >> compte.last_name;
	cout << "Adresse mail : "; cin >> compte.email;
	cout << "Password : "; cin >> compte.password;
	cout << "Confirme Password : "; cin >> np;
	while (compte.password != np)
	{
		cout << "Password : "; cin >> compte.password;
		cout << "Confirme Password : "; cin >> np;
	}
	cout << "Cin : "; cin >> compte.carte_cin;
	while (compte.carte_cin < 10000000 || compte.carte_cin>99999999)
	{
		cout << "incorecct cin contains of 8 caracters......!\n";
		cout << "Please enter Correct Cin : "; cin >> compte.carte_cin;
	}
	while (SearchExisteAccount(C, nbr_c, compte.carte_cin))
	{
		cout << "This Acounct is already in use......!\n";
		cout << "Please enter Correct Cin : "; cin >> compte.carte_cin;
	}
	compte.message = "Nothing";
	cout << "Please Wait ...\n";
	Sleep(2000);
	system("cls");
	connexion();
	Sleep(2000);
	system("cls");
	system("color 2");
	cout << "Successfully Registered\n";
	return compte;
}
int main()
{
	/*Initialiser Tableau des comptes*/
	stCompte C[100];
	int Cin_Admin = 11984993;
	C[0] = { "Tarek", "Fatnassi","tarekf91@gmail.com"  ,"1234",11984993,0,"Nothing" };
	C[1] = { "Ahemd", "Hamzaoui","hamzaoui891@gmail.com"  ,"9786",11914253,0,"Nothing" };
	C[2] = { "Sami", "dridi","sami571@gmail.com"   ,"0000",10415993 ,0 ,"Nothing" };
	C[3] = { "mokhtar", "Toumi","Toumi1@gmail.com","1919",11184918 ,0,"Nothing" };
	C[4] = { "Aziz", "Badr","azizb21@gmail.com"   ,"1925",10114925 ,0,"Nothing" };
	C[5] = { "Hamza", "Belaidi","belidi88@gmail.com"  ,"1920",11674938,0,"Nothing" };
	C[6] = { "Amine", "Sbii","amine01@gmail.com"  ,"1111",11884901 ,0 ,"Nothing" };
	C[7] = { "Ryadh", "Farahani","ryadh99@gmail.com"  ,"4321",10187911 ,0 ,"Nothing" };
	C[8] = { "Walid", "Jouini","juoini13@gmail.com"  ,"0101",11457893 ,0 ,"Nothing" };
	C[9] = { "Oussema", "lkarwy","karwy14@gmail.com","9999",13684817 ,0 ,"Nothing" };
	int nbr_c = 10;
	/*Choice the user do you want open this program*/
	string open;
	cout << "Do you want to unlock program (on\\off):\n";
	cin >> open;
	while (open != "on" && open != "ON" && open != "OFF" && open != "off")
	{
		cout << "Inccorect.!  Please enter one of the two options :\n";
		cout << "Do you want to unlock this program (on\\off):\n";
		cin >> open;
	}
	/*IF Open this is contains*/
	while (open == "on" || open == "ON")
	{
		system("cls");
		space:
		Space();
		int espace = ReadNumberRange("Please enter your Choice (0 ,1 ,2)", 0, 2);
		system("cls");
		if (espace == 0)
			goto debut;
		/*SPACE CLIENT*/
		else if (espace == 2)
		{
			welcom:
			Welcome();
			int choice = ReadNumberRange("Please enter your Choice (0 ,1 ,2)", 0, 2);
			system("cls");
			/*CHOICE 1 HAVE ACCOUNT*/
			if (choice == 1)
			{
				stCompte my_compte = ReadCompte(C, nbr_c);
				int Continue = 0;
				while (Continue == 0)
				{
					MenuSpaceClient();
					int choix;
					cout << "\n\nPlease enter your Choice: ";
					cin >> choix;
					while (choix != 0 && choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5)
					{
						cout << "Incorrect choice enter(0, 1, 2, 3, 4, 5):\n";
						cout << "Please enter your Choice : ";
						cin >> choix;
					}
					switch (choix)
					{
					case 0:
						system("cls");
						goto welcom;
						
						break;

					case 1:
						AccountStatement(C, nbr_c, my_compte.carte_cin);
						break;
					case 2:
						WithDrawMoney(C, nbr_c, my_compte.carte_cin);
						break;
					case 3:
						IncreaseMoney(C, nbr_c, my_compte.carte_cin);
						break;
					case 4:
						ClearAccount(C, nbr_c, my_compte.carte_cin);
						break;
					default:
						Help(C, nbr_c, my_compte.carte_cin);
					}
					system("cls");
					/* CHoice the user do you continue in your accout or exit*/
					cout << "Do you Want Exit in Your Accouunt:\n";
					cout << "1- Yes\n0- No\n>>";
					cin >> Continue;
					while (Continue > 1 || Continue < 0)
					{
						cout << "Please enter  0 or 1 \n";
						cout << "1- Yes\n0- No\n>>";
						cin >> Continue;
					}
					system("cls");
				}

			}
			/*User Espace Create a Account*/
			else if (choice == 0)
			{
				goto space;
			}
			else {
				AddAccount(C, nbr_c, CreateCompte(C, nbr_c));
			}
		}

		/*SPACE ADMIN*/
		else
		{
		repeats:
			system("cls");
			stCompte accountAdmin= ReadCompteAdmin();
			system("cls");
			if (VerifCompteAdmin(Cin_Admin, accountAdmin) == false)
			{
				int rep = ReadNumberRange("\ndo you want repeat: \n1- yes \n2- no\n", 1, 2);
				if (rep == 1)
					goto repeats;
				else
				    goto debut;
			}		
			else {
				int Cont = 0;
				while (Cont == 0)
				{
					
					MenuSpaceAdmin();
					cout << endl;
					int choice_admin = ReadNumberRange("Please enter your Choice (0 ,1 , 2 , 3)", 0, 3);
					system("cls");
					switch (choice_admin)
					{
					case 0:
						goto space;
					case 1:
						PrintChoiceCompte(C, nbr_c);
						break;
					case 2:
						PrintAllComptes(C, nbr_c);
						break;
					case 3:
						int carte;
						cout << "Please enter Cin for Remove : "; cin >> carte;
						while (carte < 10000000 || carte>99999999)
						{
							cout << "incorecct cin contains of 8 caracters......!\n";
							cout << "Please enter Correct Cin : "; cin >> carte;
						}
						while (SearchExisteAccount(C, nbr_c, carte)==false)
						{
							cout << "This Acounct is already in use......!\n";
							cout << "Please enter Correct Cin : "; cin >> carte;
						}
						ClearAccount(C, nbr_c, carte);
					}
					/* CHoice the user do you continue in your accout or exit*/
					cout << "\n\nDo you Want Exit in Your Accouunt:\n";
					cout << "1- Yes\n0- No\n>> ";
					cin >> Cont;
					while (Cont> 1 || Cont < 0)
					{
						cout << "Please enter  0 or 1 \n";
						cout << "1- Yes\n0- No\n>> ";
						cin >> Cont;
					}
					system("cls");
				}
			}			
			system("cls");
		}
		/*CHoice do you continue in this Program*/
		debut:
		cout << "Do you want to unlock program (on\\off):\n";
		cin >> open;
		while (open != "on" && open != "ON" && open != "OFF" && open != "off")
		{
			cout << "Inccorect.!  Please enter one of the two options :\n";
			cout << "Do you want to unlock this program (on\\off):\n";
			cin >> open;
		}
	}
	/*CLOSE THE PROGRAM*/
	cout << "\n\nThis Program is Closed\n\n";
	return 0;
}

