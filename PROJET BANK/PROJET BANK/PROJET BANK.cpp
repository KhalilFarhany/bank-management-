#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

//informations for account
struct stAccount {
	string firstName;
	string lastName;
	string email;
	string password;
	int cinCard;
	float money;
	string message;
};

//menu space 
void space()
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

//space admin
stAccount readAdminAccount()
{
	stAccount account;
	cout << "Adresse mail : "; cin >> account.email;
	cout << "Password : "; cin >> account.password;
	cout << "Cin : "; cin >> account.cinCard;

	while (account.cinCard < 10000000 || account.cinCard>99999999)
	{
		cout << "incorecct cin contains of 8 caracters......!\n";
		cout << "Please enter Correct Cin : "; cin >> account.cinCard;
	}
	cout << "Please Wait ...\n";
	Sleep(3000);
	return account;
}


bool verifAdminAccount(int cinCard,stAccount account)
{
	if (account.cinCard == cinCard)
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
void printAccount(stAccount account)
{
	cout << "First Name\t: " << account.firstName << endl;
	cout << "Last Name\t: " << account.lastName << endl;
	cout << "Email\t: " << account.email << endl;
	cout << "Cin\t: " << account.cinCard << endl;
	cout << "Monney\t: " << account.money<<" DT" << endl;
	cout << "Message\t : " << account.message << endl;
}
void printAllAccounts (stAccount accounts[],int nbrAcc)
{
	for (int i = 0; i < nbrAcc; i++)
	{
		cout << "\nAccount Number" << i + 1 << " :" << endl;
		printAccount(accounts[i]);
    }
}
void printAccountChoice(stAccount accounts[], int nbrAcc) {
	cout << "Please enter the Cin : \n";
	int cinCard;
	cin >> cinCard;
	for (int i = 0; i < nbrAcc; i++)
	{
		if (accounts[i].cinCard == cinCard)
		{
			cout << "Please Wait ...\n";
			Sleep(3000);
			system("cls");
			printAccount(accounts[i]);
			break;
		}
	}
}
void menuAdminSpace()
{
	cout << endl;
	cout << "\t\t\t\t(1) - Print Choose Account" << endl;
	cout << "\t\t\t\t(2) - Print All Accounts" << endl;
	cout << "\t\t\t\t(3) - Remove Account " << endl;
	cout << "\t\t\t\t(0) - Back " << endl;
}
/*space Client*/
int readNumberRange(string message, int from, int to)
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
void welcome()
{
	cout << "\t\t\t*********************************************\n";
	cout << "\t\t\t*** welcome in the best bank in the world ***" << endl;
	cout << "\t\t\t*********************************************\n";
	cout << "\t\t\t(1) - do you have an account ?\n";
	cout << "\t\t\t(2) - do you want to create a new account?\n";
	cout << "\t\t\t(0) - Back \n";
	cout << "\t\t\t*********************************************\n\n";
}
void menuClientSpace()
{
	cout << "\t\t\t\t(1) - Account Statement" << endl;
	cout << "\t\t\t\t(2) - WithDraaw Monney" << endl;
	cout << "\t\t\t\t(3) - Add the monney" << endl;
	cout << "\t\t\t\t(4) - Clear the Account" << endl;
	cout << "\t\t\t\t(5) - Help " << endl;
	cout << "\t\t\t\t(0) - Back " << endl;
}
void accountStatement(stAccount accounts[], int nbrAcc, int cinCard)
{
	for (int i = 0; i < nbrAcc; i++)
	{
		if (accounts[i].cinCard == cinCard)
		{
			cout << "\n" << accounts[i].lastName << " " << accounts[i].firstName << " Have in You Account " << accounts[i].money << " DT \n\n";
			Sleep(6000);
			break;
		}
	}
}
void withDrawMoney(stAccount accounts[], int nbrAcc, int cinCard) {
	int wd;
	for (int i = 0; i < nbrAcc; i++)
	{
		if (accounts[i].cinCard == cinCard)
		{

			cout << "Howa much do you Want Draw Please (dt) : ";
			cin >> wd;
			while (wd < 0) {
				cout << "Negative number .????" << endl;
				cout << "How much do you Want Draw Please (dt) : ";
				cin >> wd;
			}
			if (wd == 0)
				cout << "\nKindding With You.!\n";
			else if (wd < 10)
				cout << "\nYou can not withdraw less than 10 DT\n";
			else
			{
				if (wd > accounts[i].money)
				{
					cout << "This Amount is More Than the Amount in Your Account...!\n";
				}
				else {
					cout << "Please Wait ...\n";
					Sleep(3000);
					vector <int> numbers;
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
					accounts[i].money -= sumNumbers;
					cout << "\nOperation Accomplished Successfully\n\n";
					Sleep(4000);
				}
			}
		}
	}
}
void increaseMoney(stAccount accounts[], int nbrAcc, int cinCard) {
	int wd;
	for (int i = 0; i < nbrAcc; i++)
	{
		if (accounts[i].cinCard == cinCard)
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
				accounts[i].money += wd;
				cout << "Please Wait ...\n";
				Sleep(3000);
				cout << "Operation Accomplished Successfully\n\n";
			}
		}
	}
}

void clearAccount(stAccount accounts[], int& nbrAcc, int cinCard)
{
	for (int i = 0; i < nbrAcc; i++)
	{
		if (accounts[i].cinCard == cinCard)
		{
			for (int j = i; j < nbrAcc - 1; j++)
			{
				accounts[j] = accounts[j + 1];
			}
			nbrAcc--;
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
void addAccount(stAccount accounts[], int& nbrAcc, stAccount account)
{
	accounts[nbrAcc] = account;
	nbrAcc++;
}
void help(stAccount accounts[], int& nbrAcc, int cinCard)
{
	for (int i = 0; i < nbrAcc; i++)
	{
		if (accounts[i].cinCard == cinCard)
		{
			cout << "Send a Message To The Bank :\n";
			cin.ignore(1, '\n');
			getline(cin,accounts[i].message);
			cout << "Please Wait ...\n";
			Sleep(3000);
			cout << "Operation Accomplished Successfully\n";
			break;
		}
	}
}
int readChoice()
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
bool searchExistAccount(stAccount accounts[], int nbrAcc, int cinCard)
{
	for (int i = 0; i < nbrAcc; i++)
	{
		if (accounts[i].cinCard == cinCard)
			return true;
	}
	return false;
}
stAccount readAccount(stAccount accounts[], int nbrAcc)
{
	stAccount account;
	cout << "Adresse mail : "; cin >> account.email;
	cout << "Password : "; cin >> account.password;
	cout << "Cin : "; cin >> account.cinCard;

	while (account.cinCard < 10000000 || account.cinCard>99999999)
	{
		cout << "incorecct cin contains of 8 caracters......!\n";
		cout << "Please enter Correct Cin : "; cin >> account.cinCard;
	}
	while (searchExistAccount(accounts, nbrAcc, account.cinCard) == false)
	{
		cout << "This Cin does not exist......!\n";
		cout << "Please enter Correct Cin : "; cin >> account.cinCard;
	}
	cout << "Please Wait ...\n";
	Sleep(3000);
	system("color 2");
	cout << "opened Successfully\n";
	Sleep(3000);
	system("color 7");
	system("cls");
	return account;
}
stAccount createAccount(stAccount accounts[], int nbrAcc)
{
	cout << "PLease Enter your Information\n";
	stAccount account;
	string np;
	account.money = 0;
	cout << "Firsrt Name : "; cin >> account.firstName;
	cout << "Last Name : "; cin >> account.lastName;
	cout << "Adresse mail : "; cin >> account.email;
	cout << "Password : "; cin >> account.password;
	cout << "Confirme Password : "; cin >> np;
	while (account.password != np)
	{
		cout << "Password : "; cin >> account.password;
		cout << "Confirm Password : "; cin >> np;
	}
	cout << "Cin : "; cin >> account.cinCard;
	while (account.cinCard < 10000000 || account.cinCard>99999999)
	{
		cout << "incorecct cin contains of 8 caracters......!\n";
		cout << "Please enter Correct Cin : "; cin >> account.cinCard;
	}
	while (searchExistAccount(accounts, nbrAcc, account.cinCard))
	{
		cout << "This Acounct is already in use......!\n";
		cout << "Please enter Correct Cin : "; cin >> account.cinCard;
	}
	account.message = "Nothing";
	cout << "Please Wait ...\n";
	Sleep(2000);
	system("cls");
	connexion();
	Sleep(2000);
	system("cls");
	system("color 2");
	cout << "Successfully Registered\n";
	return account;
}
int main()
{
	stAccount accounts[100];
	int adminCin = 11984993;
	accounts[0] = { "Tarek", "Fatnassi","tarekf91@gmail.com"  ,"1234",11984993,0,"Nothing" };
	accounts[1] = { "Ahemd", "Hamzaoui","hamzaoui891@gmail.com"  ,"9786",11914253,0,"Nothing" };
	accounts[2] = { "Sami", "dridi","sami571@gmail.com"   ,"0000",10415993 ,0 ,"Nothing" };
	accounts[3] = { "mokhtar", "Toumi","Toumi1@gmail.com","1919",11184918 ,0,"Nothing" };
	accounts[4] = { "Aziz", "Badr","azizb21@gmail.com"   ,"1925",10114925 ,0,"Nothing" };
	accounts[5] = { "Hamza", "Belaidi","belidi88@gmail.com"  ,"1920",11674938,0,"Nothing" };
	accounts[6] = { "Amine", "Sbii","amine01@gmail.com"  ,"1111",11884901 ,0 ,"Nothing" };
	accounts[7] = { "Ryadh", "Farahani","ryadh99@gmail.com"  ,"4321",10187911 ,0 ,"Nothing" };
	accounts[8] = { "Walid", "Jouini","juoini13@gmail.com"  ,"0101",11457893 ,0 ,"Nothing" };
	accounts[9] = { "Oussema", "lkarwy","karwy14@gmail.com","9999",13684817 ,0 ,"Nothing" };
	int nbrAcc = 10;
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
		space();
		int espace = readNumberRange("Please enter your Choice (0 ,1 ,2)", 0, 2);
		system("cls");
		if (espace == 0)
			goto debut;
		/*SPACE CLIENT*/
		else if (espace == 2)
		{
			welcom:
			welcome();
			int choice = readNumberRange("Please enter your Choice (0 ,1 ,2)", 0, 2);
			system("cls");
			/*CHOICE 1 HAVE ACCOUNT*/
			if (choice == 1)
			{
				stAccount myAccount = readAccount(accounts, nbrAcc);
				int Continue = 0;
				while (Continue == 0)
				{
					menuClientSpace();
					int choice;
					cout << "\n\nPlease enter your Choice: ";
					cin >> choice;
					while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
					{
						cout << "Incorrect choice enter(0, 1, 2, 3, 4, 5):\n";
						cout << "Please enter your Choice : ";
						cin >> choice;
					}
					switch (choice)
					{
					case 0:
						system("cls");
						goto welcom;
						
						break;

					case 1:
						accountStatement(accounts, nbrAcc, myAccount.cinCard);
						break;
					case 2:
						withDrawMoney(accounts, nbrAcc, myAccount.cinCard);
						break;
					case 3:
						increaseMoney(accounts, nbrAcc, myAccount.cinCard);
						break;
					case 4:
						clearAccount(accounts, nbrAcc, myAccount.cinCard);
						break;
					default:
						help(accounts, nbrAcc, myAccount.cinCard);
					}
					system("cls");
					/* Choice the user do you continue in your accout or exit*/
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
				addAccount(accounts, nbrAcc, createAccount(accounts, nbrAcc));
			}
		}

		/*SPACE ADMIN*/
		else
		{
		repeats:
			system("cls");
			stAccount accountAdmin= readAdminAccount();
			system("cls");
			if (verifAdminAccount(adminCin, accountAdmin) == false)
			{
				int rep = readNumberRange("\ndo you want repeat: \n1- yes \n2- no\n", 1, 2);
				if (rep == 1)
					goto repeats;
				else
				    goto debut;
			}		
			else {
				int Cont = 0;
				while (Cont == 0)
				{
					
					menuAdminSpace();
					cout << endl;
					int adminChoice = readNumberRange("Please enter your Choice (0 ,1 , 2 , 3)", 0, 3);
					system("cls");
					switch (adminChoice)
					{
					case 0:
						goto space;
					case 1:
						printAccountChoice(accounts, nbrAcc);
						break;
					case 2:
						printAllAccounts(accounts, nbrAcc);
						break;
					case 3:
						int card;
						cout << "Please enter Cin for Remove : "; cin >> card;
						while (card < 10000000 || card>99999999)
						{
							cout << "incorecct cin contains of 8 caracters......!\n";
							cout << "Please enter Correct Cin : "; cin >> card;
						}
						while (searchExistAccount(accounts, nbrAcc, card)==false)
						{
							cout << "This Acounct is already in use......!\n";
							cout << "Please enter Correct Cin : "; cin >> card;
						}
						clearAccount(accounts, nbrAcc, card);
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

