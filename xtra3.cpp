#include <iostream> 
using namespace std; 

class Account {
    public: 
        string accountNumber; 
        string accountHolder; 
        double balance; 

        void displayDetails() {
            cout << "Account Details for Account (ID: " << accountNumber << "): " << endl; 
            cout << "   Holder: " << accountHolder << endl; 
            cout << "   Balance: $" << balance << endl; 
        }
        
        void deposit(float amount) {
            balance = balance + amount; 
        }

        void withdraw(float amount) {
            if (amount <= balance) {
                balance = balance - amount; 
            } else {
                cout << "ERROR: Insufficient funds. " << endl; 
            }
        }
};

class SavingsAccount : public Account {
    public: 
        double interestRate; 

        SavingsAccount(string num, string name, int bal, double rate) {
            accountNumber = num; 
            accountHolder = name; 
            balance = bal; 
            interestRate = rate; 
        }

        void operator+(Account obj1) {
            balance = balance - 300; 
        }

        void displayDetails() {
            cout << "Account Details for Savings Account (ID: " << accountNumber << "): " << endl; 
            cout << "   Holder: " << accountHolder << endl; 
            cout << "   Balance: $" << balance << endl; 
            cout << "   Interest Rate: " << interestRate << "%" << endl; 
        }
};

class CurrentAccount : public Account {
    public: 
        int overdraftlimit; 

        CurrentAccount(string num, string name, int bal, int limit) {
            accountNumber = num; 
            accountHolder = name; 
            balance = bal; 
            overdraftlimit = limit; 
        }

        void operator+(Account obj1) {
            balance = balance + 300; 
        }

        void displayDetails() {
            cout << "Account Details for Current Account (ID: " << accountNumber << "): " << endl; 
            cout << "   Holder: " << accountHolder << endl; 
            cout << "   Balance: $" << balance << endl; 
            cout << "   Overdraft Limit: $" << overdraftlimit << endl; 
        }

        void withdraw(float amount) {
            if (balance - amount >= -500) {
                balance = balance - amount; 
            } else {
                cout << "ERROR: Insufficient funds. " << endl; 
            }
        }
};


int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();


    cout << endl; 
    cout << "Account Details after deposit and withdrawel: " << endl; 

    savings.deposit(500);
    current.withdraw(1000);
    
    savings.displayDetails();
    current.displayDetails();


    cout << endl; 
    cout << "Account Details after transfer: " << endl; 

    // Transfer 300 from savings to current
    current + savings;
    savings + current; 

    savings.displayDetails();
    current.displayDetails();

    return 0;
}