#include <iostream>
using namespace std;
class Account {
protected:
string accountTitle;
int serialNumber;
int accountNumber;
double balance;
public:
Account(string title, int serial, int accNumber, double initialBalance) :
accountTitle(title), serialNumber(serial), accountNumber(accNumber),
balance(initialBalance) {}
virtual void credit(double amount) {
balance += amount;
cout << "Credited " << amount << " to the account." << endl;
}
virtual void debit(double amount) {
if (amount <= balance) {
balance -= amount;
cout << "Debited " << amount << " from the account." << endl;
} else {
cout << "Insufficient balance. Debit transaction failed." << endl;
}
}
virtual void calculateInterest() {
// No interest calculation for the base Account class
}
void displayBalance() {
cout << "Account Balance: " << balance << endl;
}
};
class PlusAccount : public Account {
double interestRate;
double minimumBalance;
public:
PlusAccount(string title, int serial, int accNumber, double initialBalance, double
rate, double minBalance)
: Account(title, serial, accNumber, initialBalance), interestRate(rate),
minimumBalance(minBalance) {}
void calculateInterest() {
double interest = balance * (interestRate / 100);
balance += interest;
cout << "Interest added to the Plus account: " << interest << endl;
}
};
class FreedomAccount : public Account {
double transactionFee;
double fixedInterest;
public:
FreedomAccount(string title, int serial, int accNumber, double initialBalance,
double fee, double interest)
: Account(title, serial, accNumber, initialBalance), transactionFee(fee),
fixedInterest(interest) {}
void credit(double amount) {
balance += amount - transactionFee;
cout << "Credited " << amount << " to the Freedom account (Transaction Fee: " <<
transactionFee << ")." << endl;
}
void calculateInterest() {
balance += fixedInterest;
cout << "Interest added to the Freedom account: " << fixedInterest << endl;
}
};
int main() {
Account* accounts[10]; // Array of 10 pointers to Account objects
for (int i = 0; i < 5; i++) {
string title;
int serial, accNumber;
double initialBalance;
int accountType;
cout << "Enter Account Title: ";
getline(cin, title);
cout << "Enter Serial Number: ";
cin >> serial;
cout << "Enter Account Number: ";
cin >> accNumber;
cout << "Enter Initial Balance: ";
cin >> initialBalance;
cout << "Enter Account Type (1 - Plus Account, 2 - Freedom Account): ";
cin >> accountType;
cin.ignore(); // Ignore the newline character
if (accountType == 1) {
double rate, minBalance;
cout << "Enter Interest Rate for Plus Account (%): ";
cin >> rate;
cout << "Enter Minimum Balance for Plus Account: ";
cin >> minBalance;
accounts[i] = new PlusAccount(title, serial, accNumber, initialBalance, rate,
minBalance);
} else if (accountType == 2) {
double fee, interest;
cout << "Enter Transaction Fee for Freedom Account: ";
cin >> fee;
cout << "Enter Fixed Interest for Freedom Account: ";
cin >> interest;
accounts[i] = new FreedomAccount(title, serial, accNumber, initialBalance, fee,
interest);
}
cin.ignore(); // Ignore the newline character
}
// Perform transactions for the first account
accounts[0]->credit(500);
accounts[0]->debit(200);
accounts[0]->calculateInterest();
accounts[0]->displayBalance();
// Cleanup dynamic memory
for (int i = 0; i < 5; i++) {
delete accounts[i];
}
system("pause");
return 0;
}

