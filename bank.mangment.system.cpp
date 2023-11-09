
                                        //----------------------------------------------//
                                           /*---------bank mangment system---------*/
                                        //----------------------------------------------//
#include<iostream>
#include<fstream>
#include<cctype>
// #include<windows.h>
#include<iomanip>
using namespace std;



class account
{
    
 // system("color 5a");
	int Account_No;
	char Account_Holder_Name[50];
	char type;
	int Deposit_Amount;
	
	
public:

	void Open_account();
	/* open_account function to get data
	from user and open the account */
	
	void Display_account() const;
	/* display_account function to
	show data on screen*/
	
	void Update();	
	/* update function update the old data 
	to add new data*/
	
	void dep(int);
	/* dep function to accept amount and
	add to balance amount and display to the amount*/
	
	void Withdraw(int);
	/* withdrwal function to accept amount and subtract
	from balance amount*/
	
	void report() const;	
	/* report function to show 
	data in tabular format*/
	
	int Return_Account_Number() const;	
	/* return account number function
	to return account number*/
	
	int Return_Deposit_Amount() const;	
	/* return deposit amount function 
	to return balance amount*/
	
	char Return_type() const;
	/* return type function to
	 return type of account*/
};         


void account::Display_account() const
{
    
	cout<<"\nAccount No. :: "<<Account_No;
	/*enter the account number*/

	cout<<"\nAccount Holder Name :: ";
    /*enter the account holder name*/
    
	cout<<Account_Holder_Name;
	/*account holder name */

	cout<<"\nType of Account :: "<<type;
	/*enter the account cuurent amount ya seving account*/
	

	cout<<"\nBalance amount :: "<<Deposit_Amount;
	/* show the balance amount */
	
}

void account::Open_account()
{


	cout<<"\n Enter The account No. ::";
	cin>>Account_No;

	cout<<"\n Enter The Name of The account Holder :: ";
	cin.ignore();
	cin.getline(Account_Holder_Name,50);

	cout<<"\n Enter Type of The account (C/S) :: ";
	cin>>type;
	type=toupper(type);

	cout<<"\n Enter The amount(>=500 for Saving and >=1000 for current ) :: ";
	cin>>Deposit_Amount;

	cout<<"\n\nAccount Created....";
	
	
}



void account::dep(int x)
{
    
    
	Deposit_Amount+=x;
	
/*   using the void deposit  function*/

}
	
void account::Withdraw(int x)
{
    
    
	Deposit_Amount-=x;
	
	/* using the withdraw function */
	
}
	
void account::report() const

/*using the report function*/

{
    
    
	cout<<Account_No<<setw(10)<<" "<<Account_Holder_Name<<setw(10)<<" "<<type<<setw(6)<<Deposit_Amount<<endl;
	
	
}

void account::Update()

/*using the update function*/

{
    
    
	cout<<"\nAccount No. : "<<Account_No;
	cout<<"\nUpdate Account Holder Name :: ";
	cin.ignore();
	cin.getline(Account_Holder_Name,50);

	cout<<"\nUpdate Type of Account :: ";
	cin>>type;

	type=toupper(type);
	cout<<"\nUpdate Balance amount :: ";
	cin>>Deposit_Amount;
	
	
}
	
int account::Return_Account_Number() const
{
    
    
	return Account_No;
	
/*using the return account number function*/
	
	
}


char account::Return_type() const
{
    
    
	return type;
	
	/*using the return type  function*/
	
	
}


int account::Return_Deposit_Amount() const
{
    
    
	return Deposit_Amount;
	
	/*using the return  deposit amount type  function*/
	
	
	
}


/*fonction*/


void delete_account(int);
/*function to delete record of file*/

void display_all();
/*function to display all account details*/

void write_account();
/*function to write record in binary file*/

void display_sp(int);
/*function to display account details given by user*/

void Deposit_Amount_withWithdraw(int, int); 
/* function to desposit/withWithdraw amount for given account*/


void intro();
/*introductory screen function*/

void Update_account(int);
/*function to Update record of file*/



/*--------------------------------*/
/*----------function use----------*/
/*--------------------------------*/

int main()
{
    
    
	char ch;
	int num;
	intro();
	do
	
	
	{
		system("cls");
		cout<<"\n\n\t\t ---->MAIN MENU"<<endl;

		cout<<"\n\t\t01. NEW ACCOUNT";

		cout<<"\n\t\t02. Deposit_Amount AMOUNT";

		cout<<"\n\t\t03. WITHWithdraw AMOUNT";

		cout<<"\n\t\t04. BALANCE ENQUIRY";

		cout<<"\n\t\t05. ALL ACCOUNT HOLDER LIST";

		cout<<"\n\t\t06. CLOSE AN ACCOUNT";

		cout<<"\n\t\t07. Update AN ACCOUNT";

		cout<<"\n\t\t08. EXIT";

		cout<<"\n\t\tSelect Your Option (1-8) "<<endl;
		cin>>ch;

		system("cls");
		switch(ch)
		{
		    
		    
		case '1':
			write_account();
			break;


		case '2':
			cout<<"\n\t\t Enter The account No. :: "; cin>>num;
			Deposit_Amount_withWithdraw(num, 1);
			break;


		case '3':
			cout<<"\n\t\t Enter The account No. :: "; cin>>num;
			Deposit_Amount_withWithdraw(num, 2);
			break;


		case '4': 
			cout<<"\n\t\t Enter The account No. :: "; cin>>num;
			display_sp(num);
			break;


		case '5':
			display_all();
			break;

		case '6':
			cout<<"\n\t\t Enter The account No. :: "; cin>>num;
			delete_account(num);
			break;


		 case '7':
			cout<<"\n\t\t Enter The account No. :: "; cin>>num;
			Update_account(num);
			break;


		 case '8':
			cout<<"\n\t\tThanks for using bank managemnt system..";
			break;

		 default :cout<<"\a";
		 
		 
		}
		
		
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
	
 }
 
/*function to write in file*/

void write_account()
{
    
    
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.Open_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
	
	
}

/*function to read specific record from file*/

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



/*function to Update record of file*/


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
	cout<<"--------------------------------------------------\n";
	cout<<"A/c no.      Name           Type  Balance\n";
	cout<<"--------------------------------------------------\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
	    
	    
		ac.report();
		
		
	}
	
	
	inFile.close();
	
	
}


/*  	function to Deposit_Amount and withWithdraw amounts*/


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


/*INTRODUCTION FUNCTION*/


void intro()
{


	cout<<endl<<"//------------------------------------------------------------------------------//\n           */---------- welcome to bank mangment system------------/*\n//-------------------------------------------------------------------------------//"<<endl;
	

	cin.get();
}




/*  CODE OUT PUT:-

//------------------------------------------------------------------------------//
           //---------- welcome to bank mangment system------------//
//-------------------------------------------------------------------------------//

---->MAIN MENU

		01. NEW ACCOUNT
		02. Deposit_Amount AMOUNT
		03. WITHWithdraw AMOUNT
		04. BALANCE ENQUIRY
		05. ALL ACCOUNT HOLDER LIST
		06. CLOSE AN ACCOUNT
		07. Update AN ACCOUNT
		08. EXIT
		Select Your Option (1-8) 
1
Enter The account No. ::123456
Enter The Name of The account Holder :: abhishek
Enter Type of The account (C/S) :: c
Enter The Initial amount(>=500 for Saving and >=1000 for current ) :: 4000
Account Created....
---->MAIN MENU

		01. NEW ACCOUNT
		02. Deposit_Amount AMOUNT
		03. WITHWithdraw AMOUNT
		04. BALANCE ENQUIRY
		05. ALL ACCOUNT HOLDER LIST
		06. CLOSE AN ACCOUNT
		07. Update AN ACCOUNT
		08. EXIT
		Select Your Option (1-8) 
2
Enter The account No. :: 123456
Account No. :: 123456
Account Holder Name :: abhishek
Type of Account :: C
Balance amount :: 4000
		TO Deposit_AmountE AMOUNT 
Please! Enter The amount to be Deposit_Amounted 2000
2000

		 Record Updated
		 ---->MAIN MENU

		01. NEW ACCOUNT
		02. Deposit_Amount AMOUNT
		03. WITHWithdraw AMOUNT
		04. BALANCE ENQUIRY
		05. ALL ACCOUNT HOLDER LIST
        06. CLOSE AN ACCOUNT
		07. Update AN ACCOUNT
		08. EXIT
		Select Your Option (1-8) 
3
Enter The account No. :: 123456
Account No. :: 123456
Account Holder Name :: abhishek
Type of Account :: C
Balance amount :: 6000
		TO WITHWithdraw AMOUNT 
Please! Enter The amount to be withWithdraw 3000
3000

		 Record Updated
		 ---->MAIN MENU

		01. NEW ACCOUNT
		02. Deposit_Amount AMOUNT
		03. WITHWithdraw AMOUNT
		04. BALANCE ENQUIRY
		05. ALL ACCOUNT HOLDER LIST
		06. CLOSE AN ACCOUNT
		07. Update AN ACCOUNT
		08. EXIT
Select Your Option (1-8) 
4
Enter The account No. :: 123456
BALANCE DETAILS

Account No. :: 123456
Account Holder Name :: abhishek
Type of Account :: C
Balance amount :: 3000
---->MAIN MENU

	01. NEW ACCOUNT
		02. Deposit_Amount AMOUNT
		03. WITHWithdraw AMOUNT
		04. BALANCE ENQUIRY
		05. ALL ACCOUNT HOLDER LIST
		06. CLOSE AN ACCOUNT
		07. Update AN ACCOUNT
		08. EXIT
		Select Your Option (1-8) 
5
ACCOUNT HOLDER LIST
--------------------------------------------------
A/c no.      NAME           Type  Balance
--------------------------------------------------
123456          abhishek          C  3000

---->MAIN MENU

		01. NEW ACCOUNT
		02. Deposit_Amount AMOUNT
		03. WITHWithdraw AMOUNT
		04. BALANCE ENQUIRY
		05. ALL ACCOUNT HOLDER LIST
		06. CLOSE AN ACCOUNT
		07. Update AN ACCOUNT
		08. EXIT
		Select Your Option (1-8) 
7
Enter The account No. :: 123456
Account No. :: 123456
Account Holder Name :: abhishek
Type of Account :: C
Balance amount :: 3000
Please! Enter The New Details of account

Account No. : 123456
Update Account Holder Name :: abhishek
Update Type of Account :: amount
Update Balance amount :: 300


*/


