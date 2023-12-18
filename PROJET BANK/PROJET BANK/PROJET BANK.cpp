#include <iostream>
#include <limits>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include "PROJET BANK.h"


using namespace std;



//declaration for costumer and employ account 
struct stAccount {
	string firstName;
	string lastName;
	string mailAdress;
	string password;
	int identityCardNumber;
	float money;
	string receptiveMessage; 
	string sentMessage;
};


//declaration for stAdminAccount
struct stAdminAccount {
	string firstName;
	string lastName;
	string mailAdress;
	string password;
};

//*************************** Start Global values ************************/

//list Employer account 
vector <stAccount>employeAccounts;

//list customer account
vector <stAccount>customerAccounts;

//information for admin
const string ADMIN_FIRST_NAME = "Khalyl";
const string ADMIN_LAST_NAME = "Farhani";
const string ADMIN_MAIL_ADRESS = "farhanik1919@gmail.com";
const string ADMIN_PASSWORD = "Naimanaima19*";

stAdminAccount adminAccount = {
	ADMIN_FIRST_NAME,
	ADMIN_LAST_NAME,
	ADMIN_MAIL_ADRESS,
	ADMIN_PASSWORD,
};


//remove right space
string removeRightSpace(string str) {
	while (str[str.length() - 1] == ' ') {
		str.erase(str.end() - 1);
	}
	return str;
}

bool isCorrectAdressMail(string adressMail) {
	adressMail = removeRightSpace(adressMail);
	if (adressMail.length()<4 || adressMail.substr(adressMail.length() - 4) != ".com" || adressMail.find('@') == string::npos) {
		return false;
	}
	return true;
}

/*************************************************** ADMIN SPACE ********************************************************/
void printAdminAccount() {
	cout << "First Name        : " << adminAccount.firstName << endl;
	cout << "Last Name         : " << adminAccount.lastName << endl;
	cout << "Mail Adress       : " << adminAccount.mailAdress << endl;
	cout << "Password          : " << adminAccount.password << endl;
}
//read admin acccount
stAdminAccount readAdminAccount() {
	stAdminAccount adminAcc;
	cout << "Please Enter Your Adress Mail ? " << endl << ">> ";
	cin >> adminAcc.mailAdress;

	while (!isCorrectAdressMail(adminAcc.mailAdress)) {
		cout << "\nPlease Enter Valid Adress Mail With (@example.com) ? " << endl << ">> ";
		cin >> adminAcc.mailAdress;
	}

	cout << "\nPlease Enter Your Password ? " << endl << ">> ";
	adminAcc.password = "";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 13)  // Enter key
			break;
		adminAcc.password.push_back(ch);
		cout << '*';  // Print '*' instead of the entered character
	}
	cout << endl;
	return adminAcc;
}

//verify Admin Account
bool verifyAdminAccount(stAdminAccount adminAcc) {
	if (adminAcc.mailAdress != adminAccount.mailAdress) {
		cout << "Invalid Mail Adress ..!" << endl;
		return false;
	}
	else if (adminAcc.password != adminAccount.password) {
		cout << "Invalid Password ..!" << endl;
		return false;
	}
	return true;
}

// Function to initialize an empty account
stAccount createEmptyAccount() {
	stAccount emptyAccount;
	emptyAccount.firstName = "";
	emptyAccount.lastName = "";
	emptyAccount.mailAdress = "";
	emptyAccount.password = "";
	emptyAccount.identityCardNumber = 0;
	emptyAccount.money = 0.0f;
	emptyAccount.receptiveMessage = "";
	emptyAccount.sentMessage= "";
	return emptyAccount;
}

//research Employe 
stAccount researchEmploye(int identityCardNumber) {
	for (int i = 0; i < employeAccounts.size(); i++) {
		if (identityCardNumber == employeAccounts[i].identityCardNumber)
			return employeAccounts[i];
	}
	return createEmptyAccount();
}

//research customer 
stAccount researchCustomer(int identityCardNumber) {
	for (int i = 0; i < customerAccounts.size(); i++) {
		if (identityCardNumber == customerAccounts[i].identityCardNumber)
			return customerAccounts[i];
	}
	return createEmptyAccount();
}


//verify account (employe,cutomer) is exit or no
bool verifyAccountIsExist(vector <stAccount>accounts, int identityCardNumber) {
	for (int i = 0; i < accounts.size(); i++) {
		if (identityCardNumber == accounts[i].identityCardNumber)
			return true;
	}
	return false;
}


//verify password is exist or no
bool passwordIsExist(vector <stAccount>accounts,string pass) {
	for (int i = 0; i < accounts.size(); i++) {
		if(accounts[i].password == pass) return true;
	}
	return false;
}

//verify Identity Card Number is exist or no
bool identityCardNumberIsExist(vector <stAccount>accounts, int identityCardNumber) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].identityCardNumber == identityCardNumber) return true;
	}
	return false;
}

//verify mail aderss is exist or no
bool mailAdressIsExist(vector <stAccount>accounts, string mailAdress) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].mailAdress == mailAdress) return true;
	}
	return false;
}


///----------------------------------Add Employe---------------------------------------------
void addEmploye() {
	stAccount account;

	cout << "Please Enter First Name ?  " << endl << ">> ";
	cin >> account.firstName;

	cout << "\nPlease Enter Last Name ?  " << endl << ">> ";
	cin >> account.lastName;
	
	cout << "\nPlease Enter Mail Adress ?  " << endl << ">> ";
	cin >> account.mailAdress;

	while (!isCorrectAdressMail(account.mailAdress)) {
		cout << "\nPlease Enter Valid Adress Mail With (@example.com) ? " << endl << ">> ";
		cin >> account.mailAdress;
	}

	while (mailAdressIsExist(employeAccounts, account.mailAdress)) {
		cout << "\nThis Mail Adress is Exist ..! , Please Enter Valid Mail Adress ?  " << endl << ">> ";
		cin >> account.mailAdress;
	}

	cout << "\nPlease Enter Password ?  " << endl << ">> ";
	account.password = "";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 13)  // Enter key
			break;
		account.password.push_back(ch);
		cout << '*';  // Print '*' instead of the entered character
	}
	cout << endl;

	while (passwordIsExist(employeAccounts, account.password)) {
		cout << "\nThis Password is Exist ..! , Please Enter Valid Password ?  " << endl << ">> ";
		account.password = "";
		while (1) {
			ch = _getch();
			if (ch == 13)  // Enter key
				break;
			account.password.push_back(ch);
			cout << '*';  // Print '*' instead of the entered character
		}
		cout << endl;

	}


	cout << "\nPlease Enter Identity Card Number ?  " << endl << ">> ";
	cin >> account.identityCardNumber;

	while (identityCardNumberIsExist(employeAccounts, account.identityCardNumber)) {
		cout << "\nThis Identity Card Number is Exist ..! , Please Enter Valid Identity Card Number ?  "<<endl<<">> ";
		cin >> account.identityCardNumber;
	}

	while (account.identityCardNumber < 10000000 || account.identityCardNumber>99999999)
	{
		cout << "\nInvalid Identify Card , Contains Of 8 Caracters..!\n\n";
		cout << "Please Enter Valid Identity Card Number ? " << endl << ">> ";
		cin >> account.identityCardNumber;
	}

	account.money = 0;
	account.sentMessage = "Nothing";
	account.receptiveMessage = "Nothing";
	employeAccounts.push_back(account);
	Sleep(2000);
	system("cls");
	system("color 2");
	cout << "elmowedhef ajouter\n";
	Sleep(3000);
	system("cls");
}

///enter identityCardNumber for research account
int readIdentityCardNumber() {
	int identityCardNumber;
	cout << "Please Enter Identity Card Number For Research ?  "<<endl<<">> ";
	cin >> identityCardNumber;

	while (identityCardNumber < 10000000 || identityCardNumber>99999999)
	{
		cout << "\nInvalid Identify Card , Contains Of 8 Caracters..!\n\n";
		cout << "Please Enter Valid Identity Card Number ? "<<endl<<">> ";
		cin >> identityCardNumber;
	}
	return identityCardNumber;
}

///enter identityCardNumber for the one you want to send to
int readIdentityCardNumberSent() {
	int identityCardNumber;
	cout << "Please Enter Identity Card Number The One You Want To Send To For Research ?  " << endl << ">> ";
	cin >> identityCardNumber;

	while (identityCardNumber < 10000000 || identityCardNumber>99999999)
	{
		cout << "\nInvalid Identify Card , Contains Of 8 Caracters..!\n\n";
		cout << "Please Enter Valid Identity Card Number ? " << endl << ">> ";
		cin >> identityCardNumber;
	}
	return identityCardNumber;
}

///----------------------------------Delete Employe------------------------------------------
void deleteEmploye(int identityCardNumber ) {
	for (int i = 0; i < employeAccounts.size(); i++) {
		if (employeAccounts[i].identityCardNumber == identityCardNumber) {
			employeAccounts.erase(employeAccounts.begin() + i);
			Sleep(2000);
			system("color 2");
			system("cls");
			cout << "elmowedhef tefsekh\n";
			Sleep(3000);
			system("cls");
			break;
		}
	}

}

///----------------------------------Add Salary To Employe------------------------------------------
void addSalaryToEmploye(vector <stAccount>&accounts, int identityCardNumber) {
			
			for (int i = 0; i < accounts.size(); i++) {
				if (accounts[i].identityCardNumber == identityCardNumber) {
					float salary;
					cout << "How much salary do you want to add ? " << endl << ">> ";
					cin >> salary;
					accounts[i].money += salary;
					Sleep(2000);
					system("color 2");
					system("cls");
					cout << "elflous tsabet\n";
					Sleep(3000);
					system("cls");
					break;
				}
			}
}



///----------------------------------reply to message------------------------------------------
void replyMessage(vector <stAccount>&accounts, int identityCardNumber) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].identityCardNumber == identityCardNumber) {
			if (accounts[i].sentMessage != "Nothing") {
				cout << "The Message : " << endl;
				cout << accounts[i].sentMessage << endl << endl;
				cout << "The Answer : " <<endl << ">> ";
				cin >> accounts[i].receptiveMessage;
			}
			else {
				cout << "He Doesn't Have Message" << endl;
				Sleep(3000);
			}
			break;
		}
	}	
}

///----------------------------- reply to all messages-----------------------------------------
//number Receptive Message from (Employ,Customer)
int numberReceptiveMessages(vector <stAccount>accounts) {
	int nb = 0;
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].sentMessage != "Nothing") nb++;
	}
	return nb;
}

void replyAllMessages(vector <stAccount>&accounts) {
	int j = 1;
	cout << "You Have " << numberReceptiveMessages(accounts) << " Messages \n\n";
	for (int i = 0; i < accounts.size();i++) {
		if (accounts[i].sentMessage != "Nothing") {
			cout << "Message Number "<<j<<" : " << endl;
			j++;
			cout << accounts[i].sentMessage << endl << endl;
			cout << "Response To The Message ? " << endl;
			cin >> accounts[i].receptiveMessage;
			cout << endl;
		}
	}
	Sleep(3000);
}

///----------------------------- Print (Employ,Customer)----------------------------------------
void printAccount(stAccount account) {
	cout << "First Name        : " << account.firstName << endl;
	cout << "Last Name         : " << account.lastName<<endl;
	cout << "ID Card Number    : " << account.identityCardNumber << endl;
    cout << "Mail Adress       : " << account.mailAdress << endl;
	cout << "Password          : " << account.password << endl;
	cout << "Money             : " << account.money<< endl;
	cout << "Sent Message      : " << account.sentMessage << endl;
	cout << "Receptive Message : " << account.receptiveMessage << endl;
}

void printAccountChoice(vector <stAccount> accounts, int identityCardNumber) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].identityCardNumber == identityCardNumber) {
			printAccount(accounts[i]);
		}
	}
}

///----------------------------- Print All (Employ,Customer)----------------------------------------
void printAllAccounts(vector <stAccount>accounts) {
	cout << "you have " << accounts.size() << " account \n\n";
	for (int i = 0; i < accounts.size();i++) {
		cout << ">>>   Account Number " <<i + 1 << "   <<<" << endl;
		printAccount(accounts[i]);
		cout << endl << endl;
	}
}

//administrator choices menu
void adminChoicesMenu() {
	string str1 = "", str2 = "";
	for (int i = 0; i < 50; i++)
		str1 += char(196);
	for (int i = 0; i < 10; i++)
		str2 += char(196);
	cout << char(218) << str1 + str2 + char(196) << char(191) << endl;
	cout << char(179) << "                         ADMINISTRATOR SPACE                 " << char(179) << endl;
	cout << char(195) << str2 << char(194) << str1 << char(180) << endl;
	cout << char(179) << "  Choices " << char(179) << "                  FUNCTIONS                       " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    1     " << char(179) << "   My Profil                                      " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    2     " << char(179) << "   Add Employe                                    " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    3     " << char(179) << "   Delete Employe                                 " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    4     " << char(179) << "   Add Salary To Employe                          " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    5     " << char(179) << "   Reply To a Message                             " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    6     " << char(179) << "   Reply To All Messages                          " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    7     " << char(179) << "   Print Employe                                  " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    8     " << char(179) << "   Print All Employes                             " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    0     " << char(179) << "   Back                                           " << char(179) << endl;
	cout << char(192) << str2 << char(193) << str1 << char(217) << endl;
}


/*************************************************** Employe ********************************************************/
//read Employe acccount
stAccount readEmployeAccount() {
	stAccount employeAcc;
	cout << " Please Enter Your Adress Mail ? " << endl << ">> ";
	cin >> employeAcc.mailAdress;

	while (!isCorrectAdressMail(employeAcc.mailAdress)) {
		cout << "\nPlease Enter Valid Adress Mail With (@example.com) ? " << endl << ">> ";
		cin >> employeAcc.mailAdress;
	}

	cout << " Please Enter Your Password ? " << endl << ">> ";
	employeAcc.password = "";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 13)  // Enter key
			break;
		employeAcc.password.push_back(ch);
		cout << '*';  // Print '*' instead of the entered character
	}
	cout << endl;

	bool test = false;
	for (int i = 0; i < employeAccounts.size(); i++) {
		if (employeAcc.mailAdress == employeAccounts[i].mailAdress) {
			if (employeAcc.password == employeAccounts[i].password) {
				cout << "Welcome " << employeAccounts[i].firstName << " " << employeAccounts[i].lastName << endl;
				return employeAccounts[i];
			}
			else {
				cout << "Invalid Password ..!" << endl;
			}
		}
	}
	return createEmptyAccount();
}

//Employe choices menu
void employeChoicesMenu() {
	string str1 = "", str2 = "";
	for (int i = 0; i < 50; i++)
		str1 += char(196);
	for (int i = 0; i < 10; i++)
		str2 += char(196);
	cout << char(218) << str1 + str2 + char(196) << char(191) << endl;
	cout << char(179) << "                           EMPLOYE SPACE                     " << char(179) << endl;
	cout << char(195) << str2 << char(194) << str1 << char(180) << endl;
	cout << char(179) << "  Choices " << char(179) << "                  FUNCTIONS                       " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    1     " << char(179) << "   My Profil                                      " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    2     " << char(179) << "   Reply To a Message                             " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    3     " << char(179) << "   Reply To All Messages                          " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    4     " << char(179) << "   Print Customer                                 " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    5     " << char(179) << "   Print All Customer                             " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    6     " << char(179) << "   Help                                           " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    0     " << char(179) << "   Back                                           " << char(179) << endl;
	cout << char(192) << str2 << char(193) << str1 << char(217) << endl;
}

//-----------------------------------------------help (customer , employe)-----------------------------------------
void help(vector<stAccount> &accounts, int identityCardNumber)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].identityCardNumber == identityCardNumber)
		{
			cout << "Please Enter Your Message ? " << endl << ">> ";
			cin.ignore(1, '\n');
			getline(cin, accounts[i].sentMessage);
			accounts[i].receptiveMessage="Nothing";
			cout << "\n\nPlease Wait ...\n";
			Sleep(2000);
			cout << "Operation Accomplished Successfully\n";
			Sleep(2000);
			break;
		}
	}
}

///create message (Customer , Employe)
void createMessage(vector <stAccount>&accounts, int identityCardNumber) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].identityCardNumber == identityCardNumber) {
			cout << "Please Enter Your Message For Help ?" <<endl << ">> ";
			cin >> accounts[i].sentMessage;
			break;
		}
	}
}

/******************************************************************************** CUSTOMER SPACE ************************************************************************************/

// hahah Topnet
void connection()
{
	COORD cursorPosition;
	HANDLE hConsole;
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
			Sleep(1);
		else if (i % 5 == 0)
			Sleep(5);
		else if (i == 99)
			Sleep(4);
		else
			Sleep(200);
		if (i != 100)
			system("cls");
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		// Positionne le curseur à la ligne 5, colonne 10 (les positions commencent à partir de 0)
		cursorPosition = { 107, 1 };
		SetConsoleCursorPosition(hConsole, cursorPosition);
		cout << ":)";

		cursorPosition = { 0, 0 };
		SetConsoleCursorPosition(hConsole, cursorPosition);

		// Positionne le curseur à la ligne 5, colonne 10 (les positions commencent à partir de 0)
	}
	cursorPosition = { 0, 4 };
	SetConsoleCursorPosition(hConsole, cursorPosition);
}

//create a new customer account 
void CreateCustomerAccount() {
	stAccount account;
	cout << "Please Enter First Name ?  " << endl << ">> ";
	cin >> account.firstName;
	cout << "\nPlease Enter Last Name ?  " << endl << ">> ";
	cin >> account.lastName;

	cout << "\nPlease Enter Mail Adress ?  " << endl << ">> ";
	cin >> account.mailAdress;

	while (!isCorrectAdressMail(account.mailAdress)) {
		cout << "\nPlease Enter Valid Adress Mail With (@example.com) ? " << endl << ">> ";
		cin >> account.mailAdress;
	}
	

	while (mailAdressIsExist(customerAccounts, account.mailAdress)) {
		cout << "\nThis Mail Adress is Exist ..! , Please Enter Valid Mail Adress ?  " << endl << ">> ";
		cin >> account.mailAdress;
	}

	cout << "\nPlease Enter Password ?  " << endl << ">> ";
	account.password = "";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 13)  // Enter key
			break;
		account.password.push_back(ch);
		cout << '*';  // Print '*' instead of the entered character
	}
	cout << endl;
	while (passwordIsExist(customerAccounts, account.password)) {
		cout << "\This Password is Exist ..! , Please Enter Valid Password ?  " << endl << ">> ";
		account.password = "";
		char ch;
		while (1) {
			ch = _getch();
			if (ch == 13)  // Enter key
				break;
			account.password.push_back(ch);
			cout << '*';  // Print '*' instead of the entered character
		}
		cout << endl;
	}


	cout << "\nPlease Enter Identity Card Number  ?  " << endl << ">> ";
	cin >> account.identityCardNumber;
	while (identityCardNumberIsExist(customerAccounts, account.identityCardNumber)) {
		cout << "\nThis Identity Card Number is Exist ..! , Please Enter Valid Identity Card Number ?  " << endl << ">> ";
		cin >> account.identityCardNumber;
	}

	while (account.identityCardNumber < 10000000 || account.identityCardNumber>99999999)
	{
		cout << "\nInvalid Identify Card , Contains Of 8 Caracters..!\n\n";
		cout << "\nPlease Enter Valid Identity Card Number ?" << endl << ">> ";
		cin >> account.identityCardNumber;
	}

	account.money = 0;
	account.sentMessage = "Nothing";
	account.receptiveMessage = "Nothing";
	system("cls");
	connection();
	cout << "Successfully Registered\n";
	customerAccounts.push_back(account);
}

///---------------------------------- Delete Employe------------------------------------------
void deleteCustomerAccount(int identityCardNumber) {
	for (int i = 0; i < customerAccounts.size(); i++) {
		if (customerAccounts[i].identityCardNumber == identityCardNumber) {
			customerAccounts.erase(customerAccounts.begin() + i);
			break;
		}
	}
}

///----------------------------------- Add money --------------------------------------------
void addMoney(int identityCardNumber) {
	int money;
	for (int i = 0; i < customerAccounts.size(); i++) {
		if (customerAccounts[i].identityCardNumber = identityCardNumber) {
			cout << "How Much Do You Want To Add Please (dt) ?  " << endl << ">> ";
			cin >> money;
			while (money < 0)
			{
				cout << "Negative Number .????" << endl;
				cout << "How Much Do You Want To Add Please (dt) ?  " << endl << ">> ";
				cin >> money;
			}
			if (money == 0)
				cout << "\nKindding With You.!\n";
			else {
				customerAccounts[i].money += money;
				cout << "\n\nPlease Wait ...";
				Sleep(2000);
				cout << "\nOperation Accomplished Successfully\n\n";
				Sleep(2000);
			}
			break;
		}
	}
	
			
}

///----------------------------------- WithDraw customer ------------------------------------
void withDrawMoney(int identityCardNumber) {
int wd;
for (int i = 0; i < customerAccounts.size(); i++) {
	if (customerAccounts[i].identityCardNumber = identityCardNumber)
	{
	EnterMoney:
		system("cls");
		cout << "How much do you Want Draw Please (dt) ? " << endl << ">> ";
		cin >> wd;
		while (wd < 0) {
			cout << "Negative number .????" << endl;
			cout << "How much do you Want Draw Please (dt) ? " << endl << ">> ";
			cin >> wd;
		}
		if (wd == 0)
		{
			cout << "\nKindding With You.!\n";
			Sleep(2000);
			goto EnterMoney;
		}

		else if (wd < 10)
		{
			cout << "\nYou can not withdraw less than 10 DT\n";
			Sleep(2000);
			goto EnterMoney;
		}
		else
		{
			if (wd > customerAccounts[i].money)
			{
				cout << "This Money is More Than the Money in Your Account...!\n";
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
				}
				cout << "\nI Gave You " << sumNumbers << "DT\n" << endl;
				customerAccounts[i].money -= sumNumbers;
				cout << "\nOperation Accomplished Successfully\n\n";
				Sleep(3000);
			}
		}
		break;
	}
 }
}

//transfert money 
void transfertMoney(int myIdentityCardNumber ,int identityCartNumber) {
	for (int j = 0; j < customerAccounts.size(); j++) {
		if (customerAccounts[j].identityCardNumber == myIdentityCardNumber) {
			for (int i = 0; i < customerAccounts.size(); i++) {
				if (identityCartNumber == customerAccounts[i].identityCardNumber) {
					int amount;
					stAccount acc;

					do {
						cout << "How Much Amount Do You Want To Send ? " << endl << ">> ";
						cin >> amount;
						if (amount <= 0)
							cout << "\n\nKindding With You.!\n\n";
					} while (amount <= 0);

					system("cls");
					cout << "Please Enter Your Adress Mail ? " << endl << ">> ";
					cin >> acc.mailAdress;

					while (!isCorrectAdressMail(acc.mailAdress)) {
						cout << "\nPlease Enter Valid Adress Mail With (@example.com) ? " << endl << ">> ";
						cin >> acc.mailAdress;
					}

					cout << "\nPlease Enter Your Password ? " << endl << ">> ";
					acc.password = "";
					char ch;
					while (1) {
						ch = _getch();
						if (ch == 13)  // Enter key
							break;
						acc.password.push_back(ch);
						cout << '*';  // Print '*' instead of the entered character
					}
					cout << endl;

					bool test = true;
					if (acc.mailAdress != customerAccounts[j].mailAdress) {
						cout << "\n\nInvalid Mail Adress ..!" << endl;
						test = false;
						Sleep(2000);
					}
					else if (acc.password != customerAccounts[j].password) {
						cout << "\n\nInvalid Password ..!" << endl;
						test = false;
						Sleep(2000);
					}
					if (test) {
						if (amount > customerAccounts[j].money) {
							cout << "\n\nYou Don't Have That Amount \n\n";
							Sleep(2000);
							break;
						}
						else {
							customerAccounts[j].money -= amount;
							customerAccounts[i].money += amount;
							Sleep(2000);
							system("cls");
							system("COLOR 2");
							cout << "Operation Accomplished Successfully\n";
							Sleep(3000);
							system("cls");
						}
					}
					else break;
				}
			}
			break;
		}
	}
}


//customer choices menu
void customerChoicesMenu() {
	string str1 = "", str2 = "";
	for (int i = 0; i < 50; i++)
		str1 += char(196);
	for (int i = 0; i < 10; i++)
		str2 += char(196);
	cout << char(218) << str1 + str2 + char(196) << char(191) << endl;
	cout << char(179) << "                           CUSTOMER MENU                     " << char(179) << endl;
	cout << char(195) << str2 << char(194) << str1 << char(180) << endl;
	cout << char(179) << "  Choices " << char(179) << "                  FUNCTIONS                       " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    1     " << char(179) << "   My Profil                                      " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    2     " << char(179) << "   Add Money                                      " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    3     " << char(179) << "   WithDraw Money                                 " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    4     " << char(179) << "   Transfert Money                                " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    5     " << char(179) << "   Help                                           " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    0     " << char(179) << "   Back                                           " << char(179) << endl;
	cout << char(192) << str2 << char(193) << str1 << char(217) << endl;
}


//spaces menu
void spaces() {
	string str1 = "", str2 = "";
	for (int i = 0; i < 50; i++)
		str1 += char(196);
	for (int i = 0; i < 10; i++)
		str2 += char(196);
	cout << char(218) << str1 + str2 + char(196) << char(191) << endl;
	cout << char(179) << "               Welcome In The Best Bank In The World         " << char(179) << endl;
	cout << char(195) << str2 << char(194) << str1 << char(180) << endl;
	cout << char(179) << "  Choices " << char(179) << "                  Direction                       " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    1     " << char(179) << "   Administrator Space                            " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    2     " << char(179) << "   Employe Space                                  " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    3     " << char(179) << "   Customer Space                                 " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    0     " << char(179) << "   Exit                                           " << char(179) << endl;
	cout << char(192) << str2 << char(193) << str1 << char(217) << endl;
}



//customer account
void cutomerConnection() {
	string str1 = "", str2 = "";
	for (int i = 0; i < 50; i++)
		str1 += char(196);
	for (int i = 0; i < 10; i++)
		str2 += char(196);
	cout << char(218) << str1 + str2 + char(196) << char(191) << endl;
	cout << char(179) << "		    	  CUSTOMER ACCOUNT                    " << char(179) << endl;
	cout << char(195) << str2 << char(194) << str1 << char(180) << endl;
	cout << char(179) << "  Choices " << char(179) << "                  Function                        " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    1     " << char(179) << "   Sign in                                        " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    2     " << char(179) << "   Sign up                                        " << char(179) << endl;
	cout << char(195) << str2 << char(197) << str1 << char(180) << endl;
	cout << char(179) << "    0     " << char(179) << "   Back                                           " << char(179) << endl;
	cout << char(192) << str2 << char(193) << str1 << char(217) << endl;
}


//read account (employe / customer)
stAccount readAccount() {
	stAccount acc=createEmptyAccount();
	cout << "Please Enter Your Adress Mail ? " << endl << ">> ";
	cin >> acc.mailAdress;

	while (!isCorrectAdressMail(acc.mailAdress)) {
		cout << "\nPlease Enter Valid Adress Mail With (@example.com) ? " << endl << ">> ";
		cin >> acc.mailAdress;
	}

	cout << "\nPlease Enter Your Password ? " << endl << ">> ";
	acc.password = "";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 13)  // Enter key
			break;
		acc.password.push_back(ch);
		cout << '*';  // Print '*' instead of the entered character
	}
	cout << endl;
	return acc;
}


/// verify Account is exist by adress and password
bool verifyAccount(vector<stAccount> accounts, stAccount& acc) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].mailAdress == acc.mailAdress) 
			if (accounts[i].password != acc.password) {
				cout << "Invalid Password ..!" << endl;
				return false;
			}
			else {
				acc = accounts[i];
				return true;
			}	
	}
	cout << "This Adress Mail Does Not Exist\n";
	return false;
}

int readNumberRange(string message, int from, int to)
{
	int number;
	cout << message << "\n>> ";
	cin >> number;
	while (number <from || number>to)
	{
		cout << message << "\n>> ";
		cin >> number;
	}
	return number;
}


int main()
{
	//declaration 
	bool b;
	int spaceChoice;
	int adminChoice;
	int employeChoice;
	int connectionChoiceCustomer;
	int customerChoice;
	stAdminAccount adminAccount;
	int count ;
	int choiceTry;
	int identityCardNumber;
	stAccount employeAccount;
	stAccount customerAccount;

Spaces:
	system("cls");
	system("COLOR 0F");
	count = 2;
	spaces();
	cout << endl<<endl;
	spaceChoice = readNumberRange("Please Enter Your Space ? ", 0, 3);
	system("cls");
	switch (spaceChoice) {
	case 1:
		adminAccount = readAdminAccount();
		cout << endl;
		b= verifyAdminAccount(adminAccount);
		while (!b && count--) {
			Sleep(2000);
			system("cls");
			cout << "\n 1  -  Try Again \n";
			cout << " 0  -  Back \n\n";
			choiceTry = readNumberRange("Please Enter Your Choice ? ", 0, 1);
			system("cls");
			if (!choiceTry) {
				goto Spaces;
			}
			adminAccount = readAdminAccount();
			cout << endl;
			b = verifyAdminAccount(adminAccount);
		}
		if (!b) {
			Sleep(2000);
			system("cls");
			cout << "Sorry You Have Three Trys :(\n";
			system("COLOR 4F");
			Sleep(2000);
			goto Spaces;
		}
		else {
		AdministratorMenu:
			system("cls");
			system("COLOR 0F");
			adminChoicesMenu();
			cout << "\n\n";
			adminChoice = readNumberRange("Please Enter Your Choice ? ", 0, 8);
			system("cls");
			switch (adminChoice) {
			case 1:
				printAdminAccount();
				cout << "\n\n";
				system("pause");
				goto AdministratorMenu;
			case 2:
				cout << "+ Information New Employe +\n\n";
				addEmploye();
				goto AdministratorMenu;
			case 3:
				if (employeAccounts.size() == 0) {
					cout << "LA YOUJEB MOWADHIFIN"<<endl;
					Sleep(3000);
				}
				else {
					identityCardNumber = readIdentityCardNumber();
					if (identityCardNumberIsExist(employeAccounts, identityCardNumber)) 
					    deleteEmploye(identityCardNumber);
					else {
						system("cls");
						cout << "This Identity Card Number is Not Exist ..!"<<endl;
						Sleep(3000);
					}
				}
				goto AdministratorMenu;
			case 4:
				identityCardNumber = readIdentityCardNumber();
				if (identityCardNumberIsExist(employeAccounts, identityCardNumber)) {
					system("cls");
					addSalaryToEmploye(employeAccounts, identityCardNumber);
				}
				else {
					system("cls");
					cout << "This Identity Card Number is Not Exist ..!" << endl;
					Sleep(3000);
				}
				goto AdministratorMenu;
			case 5:
				identityCardNumber = readIdentityCardNumber();
				if (identityCardNumberIsExist(employeAccounts, identityCardNumber)) {
					system("cls");
					replyMessage(employeAccounts, identityCardNumber);
				}
				else {
					system("cls");
					cout << "This Identity Card Number is Not Exist ..!" << endl;
					Sleep(3000);
				}
				goto AdministratorMenu;
			case 6:
				replyAllMessages(employeAccounts);
				goto AdministratorMenu;
			case 7:
				identityCardNumber = readIdentityCardNumber();
				if (identityCardNumberIsExist(employeAccounts, identityCardNumber)) {
					system("cls");
					printAccountChoice(employeAccounts, identityCardNumber);
					cout << "\n\n\n";
					system("pause");
				}
				else {
					system("cls");
					cout << "This Identity Card Number is Not Exist ..!" << endl;
					Sleep(3000);
				}
				goto AdministratorMenu;
			case 8:
				printAllAccounts(employeAccounts);
				cout << "\n\n\n";
				system("pause");
				goto AdministratorMenu;
			case 0:
				goto Spaces;
			}
		}
		goto Spaces;

	case 2:
		employeAccount = readAccount();
		cout << endl;
		b = verifyAccount(employeAccounts,employeAccount);
		while (!b && count--) {
			Sleep(2000);
			system("cls");
			cout << "\n 1  -  Try Again \n";
			cout << " 0  -  Back \n\n";
			choiceTry = readNumberRange("Please Enter Your Choice ? ", 0, 1);
			system("cls");
			if (!choiceTry) {
				goto Spaces;
			}
			employeAccount = readAccount();
			cout << endl;
			b = verifyAccount(employeAccounts, employeAccount);
		}
		if (!b) {
			Sleep(2000);
			system("cls");
			cout << "Sorry You Have Three Trys :(\n";
			system("COLOR 4F");
			Sleep(2000);
			goto Spaces;
		}
	EmployeMenu:
		system("cls");
		system("COLOR 0F");
		employeChoicesMenu();
		cout << "\n\n";
		employeChoice = readNumberRange("Please Enter Your Choice ? ", 0, 6);
		system("cls");
		switch (employeChoice) {
		case 1:
			employeAccount = researchEmploye(employeAccount.identityCardNumber);
			printAccount(employeAccount);
			cout << "\n\n";
			system("pause");
			goto EmployeMenu;
		case 2:
			identityCardNumber = readIdentityCardNumber();
			if (identityCardNumberIsExist(customerAccounts, identityCardNumber)) {
				system("cls");
				replyMessage(customerAccounts, identityCardNumber);
			}
			else {
				system("cls");
				cout << "This Identity Card Number is Not Exist ..!" << endl;
				Sleep(3000);
			}
			goto EmployeMenu;
		case 3:
			replyAllMessages(customerAccounts);
			goto EmployeMenu;
		case 4:
			identityCardNumber = readIdentityCardNumber();
			if (identityCardNumberIsExist(customerAccounts, identityCardNumber)) {
				system("cls");
				printAccountChoice(customerAccounts, identityCardNumber);
				cout << "\n\n\n";
				system("pause");
			}
			else {
				system("cls");
				cout << "This Identity Card Number is Not Exist ..!" << endl;
				Sleep(3000);
			}
			goto EmployeMenu;
		case 5:
			printAllAccounts(customerAccounts);
			cout << "\n\n\n";
			system("pause");
			goto EmployeMenu;
		case 6:
			help(employeAccounts, employeAccount.identityCardNumber);
			goto EmployeMenu;
		case 0:
			goto Spaces;
		}
		break;
	case 3:
	CustomerAccount:
		system("cls");
		system("COLOR 0F");
		cutomerConnection();
		cout << endl<<endl;
		connectionChoiceCustomer = readNumberRange("Please Enter Your Choice ? ", 0, 2);
		system("cls");
		switch (connectionChoiceCustomer) {
		case 1:
			customerAccount = readAccount();
			cout << endl;
			b = verifyAccount(customerAccounts, customerAccount);
			while (!b && count--) {
				Sleep(2000);
				system("cls");
				cout << "\n 1  -  Try Again \n";
				cout << " 0  -  Back \n\n";
				choiceTry = readNumberRange("Please Enter Your Choice ? ", 0, 1);
				system("cls");
				if (!choiceTry) {
					goto CustomerAccount;
				}
				/*********---------------*/
				customerAccount = readAccount();
				cout << endl;
				b = verifyAccount(customerAccounts, customerAccount);
			}
			if (!b) {
				Sleep(2000);
				system("cls");
				cout << "Sorry You Have Three Trys :(\n";
				system("COLOR 4F");
				Sleep(2000);
				goto CustomerAccount;
			}
		CustomerMenu:
			system("cls");
			system("COLOR 0F");
			customerChoicesMenu();
			cout << "\n\n";
			customerChoice = readNumberRange("Please Enter Your Choice ? ", 0, 5);
			system("cls");
			switch (customerChoice) {
			case 1:
				customerAccount = researchCustomer(customerAccount.identityCardNumber);
				printAccount(customerAccount);
				cout << "\n\n";
				system("pause");
				goto CustomerMenu;
			case 2:
				addMoney(customerAccount.identityCardNumber);
				goto CustomerMenu;
			case 3:
				withDrawMoney(customerAccount.identityCardNumber);
				goto CustomerMenu;
			case 4:
				identityCardNumber = readIdentityCardNumberSent();
				if (identityCardNumberIsExist(customerAccounts, identityCardNumber)) {
					system("cls");
					transfertMoney(customerAccount.identityCardNumber, identityCardNumber);
				}
				else {
					system("cls");
					cout << "This Identity Card Number is Not Exist ..!" << endl;
					Sleep(3000);
				}	
				goto CustomerMenu;
			case 5:
				help(customerAccounts, customerAccount.identityCardNumber);
				system("cls");
				goto CustomerMenu;
			case 0:
				goto CustomerAccount;
			}
		case 2:
			CreateCustomerAccount();
			Sleep(3000);
			goto CustomerAccount;
		case 0:
			goto Spaces;
		}
		break;	
	case 0:
		break;
	}

	//CLose Program
	cout << "\n\nThis Program is Closed\n\n";

	return 0;
}

