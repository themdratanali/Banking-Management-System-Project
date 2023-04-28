#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include<cctype>
using namespace std;

void header();
void loginScreen();
void write_account();
void Deposit_Amount_withWithdraw(int, int);
void display_sp(int);
void display_all();
void Update_account(int);
void delete_account(int);

class account
{
    int Account_No;
    char Account_Holder_Name[44];
    char type;
    int Deposit_Amount;
public:
    void Open_account();
    void Display_account() const;
    void Update();
    void dep(int);
    void Withdraw(int);
    void report() const;
    int Return_Account_Number() const;
    int Return_Deposit_Amount() const;
    char Return_type() const;
};

int main()
{
    char ch;
    int num;
    header();
    loginScreen();
    do{
        system("cls");
        header();
        cout<<"\n\n\t\tMAIN MENU";
        cout<<"\n\t\t01. NEW ACCOUNT";
        cout<<"\n\t\t02. Deposit_Amount AMOUNT";
        cout<<"\n\t\t03. WITHWithdraw AMOUNT";
        cout<<"\n\t\t04. BALANCE ENQUIRY";
        cout<<"\n\t\t05. ALL ACCOUNT HOLDER LIST";
        cout<<"\n\t\t06. CLOSE AN ACCOUNT";
        cout<<"\n\t\t07. Update AN ACCOUNT";
        cout<<"\n\t\t08. EXIT";
        cout<<"\n\t\tSelect Your Option (1-8) ";
        cin>>ch;
        system("cls");
        switch(ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout<<"\n\t\tPlease! Enter The account No. : ";
            cin>>num;
            Deposit_Amount_withWithdraw(num, 1);
            break;
        case '3':
            cout<<"\n\t\tPlease! Enter The account No. : ";
            cin>>num;
            Deposit_Amount_withWithdraw(num, 2);
            break;
        case '4':
            cout<<"\n\t\tPlease! Enter The account No. : ";
            cin>>num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout<<"\n\t\tPlease! Enter The account No. : ";
            cin>>num;
            delete_account(num);
            break;
        case '7':
            cout<<"\n\t\tPlease! Enter The account No. : ";
            cin>>num;
            Update_account(num);
            break;
        case '8':
            cout<<"\n\t\tThanks for using bank managemnt system";
            break;
        default :
            cout<<"\a";
        }
        cin.ignore();
        cin.get();
    }
    while(ch!='8');
    return 0;
}

void header()
{
    cout <<"\n\t\t\t\t\t\t\t\t\t\t\t\tBank Branch:: Seattle,WA \n";
    cout <<"\t\t\t\t\t\t\t\t\t\t\t\t-------------------------\n\n";
    cout <<"\t\t\t\t\t----------------------------------------------------------------------------------\n";
    cout <<"\t\t\t\t\t|                          MR International Bank                                  |\t\t\t\t\t\t\n";
    cout <<"\t\t\t\t\t----------------------------------------------------------------------------------\n\n";
}

void loginScreen()
{
    char Username[15];
    char Password[15];
    char original_Username[25] = "admin";
    char original_Password[15] = "password";
    int i;
    for (i = 0; i < 3; i++)
    {
        cout <<"\t\t\t\t\t                        Login to MR Bank Dashboard...            \t\t \t\t\t\t\t\t\n\n";
        cout <<"\n\t\t\t\t\t\t\t\tEnter Username: ";
        cin>>Username;
        cout <<"\t\t\t\t\t\t\t\t--------------------------";
        cout <<"\n\t\t\t\t\t\t\t\tEnter Password: ";
        cin>>Password;

        if (strcmp(Username, original_Username) == 0 && strcmp(Password, original_Password) == 0)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tPassword Matched!!!...\n\t\t\t\t\t\t\t\tLogging In";
            for (i = 0; i <= 3; i++)
            {
                Sleep(100);
                cout << ".";
            }
            system("cls");
            break;
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\tPassword in incorrect...\n\t\t\t\t\t\t\t\tPlease Try Again...";
            getch();
        }
        if (i > 3)
        {
            cout << "\n\t\t\t\t\t\t\t\tYou have cross the limit....\n\t\t\t\t\t\t\t\tYour Login Is blocked....";
            getch();
            exit(1);
        }
    }
}


void account::Display_account() const
{
    cout<<"\nAccount No. : "<<Account_No;
    cout<<"\nAccount Holder Name : ";
    cout<<Account_Holder_Name;
    cout<<"\nType of Account : "<<type;
    cout<<"\nBalance amount : "<<Deposit_Amount;
}
void account::Open_account()
{
    cout<<"\nPlease! Enter The account No. :";
    cin>>Account_No;
    cout<<"\nPlease! Enter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(Account_Holder_Name,44);
    cout<<"\nPlease! Enter Type of The account (C/S) : ";
    cin>>type;
    type=toupper(type);
    cout<<"\nPlease! Enter The Initial amount(>=440 for Saving and >=1000 for current ) : ";
    cin>>Deposit_Amount;
    cout<<"\n\nAccount Created..";
}


void account::dep(int x)
{
    Deposit_Amount+=x;
}

void account::Withdraw(int x)
{
    Deposit_Amount-=x;
}

void account::report() const
{
    cout<<Account_No<<setw(10)<<" "<<Account_Holder_Name<<setw(10)<<" "<<type<<setw(6)<<Deposit_Amount<<endl;
}

void account::Update()
{
    cout<<"\nAccount No. : "<<Account_No;
    cout<<"\nUpdate Account Holder Name : ";
    cin.ignore();
    cin.getline(Account_Holder_Name,44);
    cout<<"\nUpdate Type of Account : ";
    cin>>type;
    type=toupper(type);
    cout<<"\nUpdate Balance amount : ";
    cin>>Deposit_Amount;
}

int account::Return_Account_Number() const
{
    return Account_No;
}

char account::Return_type() const
{
    return type;
}
int account::Return_Deposit_Amount() const
{
    return Deposit_Amount;
}

//function to write in file

void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ac.Open_account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
    outFile.close();
}
//function to read specific record from file

void display_sp(int n)
{
    account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";

    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        if(ac.Return_Account_Number()==n)
        {
            ac.Display_account();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\nAccount number does not exist";
}

//function to Update record of file

void Update_account(int n)
{
    bool found=false;
    account ac;
    fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
        if(ac.Return_Account_Number()==n)
        {
            ac.Display_account();
            cout<<"\nPlease! Enter The New Details of account"<<endl;
            ac.Update();
            int pos=(-1)*static_cast<int>(sizeof(account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"\n\t\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n Record Not Found ";
}

//function to delete record of file

void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        if(ac.Return_Account_Number()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"\n\t\tRecord Deleted ..";
}

//function to display all accounts Deposit_Amount list

void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\t\t\t\tACCOUNT HOLDER LIST\n";
    cout<<"*************************\n";
    cout<<"A/c no.      NAME           Type  Balance\n";
    cout<<"*************************\n";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}

//  	function to Deposit_Amount and withWithdraw amounts

void Deposit_Amount_withWithdraw(int n, int option)
{
    int Amount;
    bool found=false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
        if(ac.Return_Account_Number()==n)
        {
            ac.Display_account();
            if(option==1)
            {
                cout<<"\n\t\tTO Deposit_AmountE AMOUNT ";
                cout<<"\nPlease! Enter The amount to be Deposit_Amounted";
                cin>>Amount;
                ac.dep(Amount);
            }
            if(option==2)
            {
                cout<<"\n\t\tTO WITHWithdraw AMOUNT ";
                cout<<"\nPlease! Enter The amount to be withWithdraw";
                cin>>Amount;
                int bal=ac.Return_Deposit_Amount()-Amount;
                if((bal<440 && ac.Return_type()=='S') || (bal<1000 && ac.Return_type()=='C'))
                    cout<<"Insufficience balance";
                else
                    ac.Withdraw(Amount);
            }
            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"\n\t\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n Record Not Found ";
}
