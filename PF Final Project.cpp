#include<iostream>
#include<string>
using namespace std;

struct Transaction
{
    string date;
    string time;
    string type;
    
    double amount;
};

struct User    //structure user info
{
    string accountNumber;
    string pin;
    double balance;
    double availablelimit;
    Transaction transactions[10];
    int transactionCount;

};

void displayMenu()  
 //menu
{
	system("color 30");
	cout<<endl;
	cout<< "                                                     ----------------------------------------------------------------------------"<<endl;
	cout<<  "                                                    |                 Please select from the options below                      |"<<endl;
	cout<<"                                                    |                                                                           |"<<endl;
    cout << "                                                    |1. Balance Inquiry                                   2. Cash Withdrawal    |"<< endl;
    cout << "                                                    |3. Mini Statement                                    4. Deposit            |" << endl;
    cout << "                                                    |                            5. Exit                                        |" << endl;
    cout<< "                                                    |---------------------------------------------------------------------------|"<<endl;
    cout<<endl;
    cout << "    Enter your choice: ";
}

void balanceInquiry(const User &user) 
{ 
    system("color 10");
    cout << "  -----------------------------------------------" << endl;
    cout << "               Check Balance                  " << endl;
    cout << "  -----------------------------------------------" << endl;
    cout << "    Account Number: " << user.accountNumber << endl;
    cout << "    Account Balance: $" << user.balance << endl; 
    cout << "    Available Limit: $" << user.availablelimit << endl;
    cout<<endl;
}

void cashWithdrawal(User &user)
 { 
	  
	  system("color 80");
	  double amount; 
	  cout<<"  -----------------------------------------------" << endl;
      cout << "               Withdraw Cash                  " << endl;
      cout << "  -----------------------------------------------" << endl;
	  cout << "    Enter amount to withdraw: "; 
	  cin >> amount;
	   if (amount <= user.availablelimit && amount <= user.balance)
	    {
		 user.balance -= amount; 
		cout << "    Withdrawal successful. Your new balance is: $" << user.balance << endl; // Record transaction 
		user.transactions[user.transactionCount % 10] = {"2024-12-19", "12:00 pm", "Withdrawal", amount}; // Assuming fixed date for simplicity
		 user.transactionCount++;
		  } 
		 else 
		 { 
		 cout << "    Insufficient balance or available limit." << endl; 
		 }

}

void deposit(User &user) {
    system("color e");
    double amount;
    cout << "  -----------------------------------------------" << endl;
    cout << "                Deposit Cash                   " << endl;
    cout << "  -----------------------------------------------" << endl;
    cout << "    Enter amount to deposit: ";
    cin >> amount;
    user.balance += amount;
    cout << "    Deposit successful. Your new balance is: $ " << user.balance << endl;
    // Record transaction
    user.transactions[user.transactionCount % 10] = {"2024-12-19", "12:00 pm", "Deposit   ", amount}; // Assuming fixed date for simplicity
    user.transactionCount++;
}

void generateMiniStatement(const User &user)
 { 
 
    system("color eB");
 cout<<endl;
 cout << "                                                                      -----------------------------------------------" << endl;
 cout << "                                                                                        Mini Statement                 " << endl;
 cout << "                                                                      -----------------------------------------------" << endl;
 cout<<  "                                                           ____________________________________________________________________ "<<endl;
 cout << "                                                          |           Mini Statement for Account Number:  " << user.accountNumber <<"          |"<< endl; 
 cout<<  "                                                          |                                                                   |"<<endl;
 cout << "                                                          | Date                  Time               Type             Amount  |" << endl;
  for (int i = 0; i < user.transactionCount; ++i)
   { 
 cout << "                                                          | "<<user.transactions[i].date << "            " << user.transactions[i].time << "            " << user.transactions[i].type << "      $" << user.transactions[i].amount << endl; 
  cout<< "                                                          |                                                                   |"<<endl;
  cout<< "                                                           ____________________________________________________________________" <<endl;
  cout<<endl;
   }
    if (user.transactionCount == 0)
	 { cout << "No transactions available." << endl;
	  }
}

int main()
{
	system("color 20");
	system("color 10");
	system("color 30");
	system("color 40");
	system("color 50");
	system("color 60");
	system("color 70");
	system("color 80");
	system("color 90");
	system("color 70");
	
		User users[10] = {
		{"1234567890", "1111", 1000.0, 800.0, {}, 0}, 
		{"2345678901", "2222", 2000.0, 1800.0, {}, 0}, 
		{"3456789012", "3333", 3000.0, 2500.0, {}, 0},
		{"4567890123", "4444", 4000.0, 3500.0, {}, 0},
		{"5678901234", "5555", 5000.0, 4500.0, {}, 0},
		{"6789012345", "6666", 6000.0, 5500.0, {}, 0},
		{"7890123456", "7777", 7000.0, 6500.0, {}, 0}, 
		{"8901234567", "8888", 8000.0, 7000.0, {}, 0},
		{"9012345678", "9999", 9000.0, 8500.0, {}, 0}, 
		{"0123456789", "0000", 10000.0, 9500.0, {}, 0}
    };
	
	string enteredAccountNumber;  //card
	cout<<"~"<<endl;
	cout<<"SR BANK\n";
	cout<<"~"<<endl;
	cout<<"                                                     ________________________________________________________________\n";
	cout<<"                                                     ---------------------                 --------------------------\n";
	cout<<"                                               ----------------------- || WELCOME TO SR ATM ||--------------------------\n";
	cout<<"                                                     ---------------------                 --------------------------\n";
	cout<<"                                                     _________________________________________________________________\n";
	cout<<endl;
	cout<<endl;
	cin.get();
	system(" cls ");
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<< "     _________________________________________________________________"<<endl;
	cout<<"       Please insert your card(enter account number):  ";
	cin>>enteredAccountNumber;
	
	 int userIndex = -1;

    for (int i = 0; i < 10; ++i)
	 {
        if (users[i].accountNumber == enteredAccountNumber)
		 {
            userIndex = i;
            break;
        }
   
    }
     if (userIndex != -1) 
	 {
        string enteredPin;
        cout << "       Enter your 4 digit PIN:  ";
        cin >>     enteredPin;
        

        if (users[userIndex].pin == enteredPin) 
		{
            cout << "       PIN verified successfully!" << endl;
            
            cout<<"  _________________________________________________________________"<<endl;
            cout<<endl;
            int choice;
            do
            {
            displayMenu();
            cin >> choice;
			switch (choice) 
			{
                case 1:
                	balanceInquiry(users[userIndex]);
					 break; 
				case 2: cashWithdrawal(users[userIndex]);
					  break; 
			    case 3: generateMiniStatement(users[userIndex]); 
					  break;
			    case 4:
                        deposit(users[userIndex]);
                        break;
                case 5:
                	cout<<endl;
                        cout << "                                                         Exiting. Thank you for using the ATM!" << endl;
                        cout<<  "                                                         ______________________________________";
                        break; 
                    
			     default: cout << "Invalid choice. Please try again." <<endl;
					 break;
                }
        } while(choice!=5);
    }
		else
		 {
            cout << "Incorrect PIN. Please try again." << endl;
        }
    } 
	else
	 {
        cout << "Account not found. Please try again." << endl;
    }

    return 0;

}  //main brac