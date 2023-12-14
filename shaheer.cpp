#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class BankAccount {
protected:
    string name;
    int accountNum;
    double balance;

public:
    BankAccount() : name(""), accountNum(0), balance(0.0) {}

    BankAccount(string n, int ac, double bal) {
        name = n;
        accountNum = ac;
        balance = bal;
    }

    string GetName() {
        return name;
    }

    int GetAccountNum() {
        return accountNum;
    }

    double GetBalance() {
        return balance;
    }

    void Deposit(double amount) {
        balance += amount;
    }

    void Withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "\t\tWithdraw Successful..." << endl;
        }
        else {
            cout << "\t\tInsufficient Balance...." << endl;
        }
    }

    void Display() {
        cout << "Name: " << name << " Account Number: " << accountNum << " Balance: " << balance << endl;
    }

    void WriteToFile(ofstream& file) {
        file << name << "\n";
        file << accountNum << "\n";
        file << balance << "\n";
    }

    void ReadFromFile(ifstream& file) {
        getline(file, name);
        file >> accountNum;
        file >> balance;
        file.ignore();  // Ignore the newline character after reading balance
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount() : BankAccount(), interestRate(0.0) {}

    SavingsAccount(string n, int ac, double bal, double rate) : BankAccount(n, ac, bal) {
        interestRate = rate;
    }

    void Deposit(double amount) {
        balance += balance * (interestRate / 100);
        balance += amount;
    }

    void Display() {
        cout << "Savings Account - ";
        BankAccount::Display();
    }

    void WriteToFile(ofstream& file) {
        BankAccount::WriteToFile(file);
        file << interestRate << "\n";
    }

    void ReadFromFile(ifstream& file) {
        BankAccount::ReadFromFile(file);
        file >> interestRate;
        file.ignore();  // Ignore the newline character after reading interestRate
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount() : BankAccount(), overdraftLimit(0.0) {}

    CurrentAccount(string n, int ac, double bal, double limit) : BankAccount(n, ac, bal) {
        overdraftLimit = limit;
    }

    void Withdraw(double amount) {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "\t\tWithdraw Successful..." << endl;
        }
        else {
            cout << "\t\tInsufficient Balance. Overdraft limit reached...." << endl;
        }
    }

    void Display() {
        cout << "Current Account - ";
        BankAccount::Display();
    }

};

class BankManagement {
private:
    vector<BankAccount*> accounts;

public:
    void AddAccount(BankAccount* account) {
        accounts.push_back(account);
    }

    void ShowAllAccounts() {
        cout << "\t\tAll Account Holders" << endl;
        for (int i = 0; i < accounts.size(); i++) {
            accounts[i]->Display();
        }
    }

    void SearchAccount(int accountNum) {
        cout << "\t\tAccount Holder" << endl;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i]->GetAccountNum() == accountNum) {
                accounts[i]->Display();
                return;
            }
        }
        cout << "\t\tAccount Not Found..." << endl;
    }

    BankAccount* FindAccount(int accountNum) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i]->GetAccountNum() == accountNum) {
                return accounts[i];
            }
        }
        return NULL;
    }

   
};



int main() {
    BankManagement bank;
    int choice;
    char op;
    do {
        system("cls");
        cout << "\t\t::Bank Management System" << endl;
        cout << "\t\t\tMain Menu" << endl;
        cout << "\t\t1. Create New Account" << endl;
        cout << "\t\t2. Show All Accounts" << endl;
        cout << "\t\t3. Search Account" << endl;
        cout << "\t\t4. Deposit Money" << endl;
        cout << "\t\t5. Withdraw Money" << endl;
        cout << "\t\t6. Save Data to File" << endl;
        cout << "\t\t7. Load Data from File" << endl;
        cout << "\t\t8. Exit" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\tEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int accountNum;
            double balance;
            double interestRate;
            double overdraftLimit;

            cout << "\t\tEnter Name: ";
            cin >> name;
            cout << "\t\tEnter Account Number: ";
            cin >> accountNum;
            cout << "\t\tEnter Initial Balance: ";
            cin >> balance;

            int accountType;
            cout << "\t\tSelect Account Type:" << endl;
            cout << "\t\t1. Savings Account" << endl;
            cout << "\t\t2. Current Account" << endl;
            cout << "\t\tEnter Account Type: ";
            cin >> accountType;

            if (accountType == 1) {
                cout << "\t\tEnter Interest Rate (%): ";
                cin >> interestRate;
                SavingsAccount account(name, accountNum, balance, interestRate);
                bank.AddAccount(account);
            }
            else if (accountType == 2) {
                cout << "\t\tEnter Overdraft Limit: ";
                cin >> overdraftLimit;
                CurrentAccount account(name, accountNum, balance, overdraftLimit);
                bank.AddAccount(account);
            }

            cout << "\t\tAccount Created Successfully...." << endl;
            break;
        }
        case 2: {
            bank.ShowAllAccounts();
            break;
        }
        case 3: {
            int accountNum;
            cout << "Enter Account Number: ";
            cin >> accountNum;
            bank.SearchAccount(accountNum);
            break;
        }
        case 4: {
            int accountNum;
            double amount;
            cout << "\t\tEnter Account Number to Deposit Money: ";
            cin >> accountNum;
            BankAccount* account = bank.FindAccount(accountNum);
            if (account != NULL) {
                cout << "\t\tEnter Amount to Deposit: ";
                cin >> amount;
                account->Deposit(amount);
                cout << "\t\t" << amount << " Deposited Successfully...." << endl;
            }
            else {
                cout << "\t\tAccount Not Found..." << endl;
            }
            break;
        }
        case 5: {
            int accountNum;
            double amount;
            cout << "\t\tEnter Account Number to Withdraw Money: ";
            cin >> accountNum;
            BankAccount* account = bank.FindAccount(accountNum);
            if (account != NULL) {
                cout << "\t\tEnter Amount to Withdraw: ";
                cin >> amount;
                account->Withdraw(amount);
            }
            else {
                cout << "\t\tAccount Not Found..." << endl;
            }
            break;
        }
        case 6: {
            string fileName;
            cout << "Enter file name to save data: ";
            cin >> fileName;
            bank.WriteToFile(fileName);
            break;
        }
        case 7: {
            string fileName;
            cout << "Enter file name to load data: ";
            cin >> fileName;
            bank.ReadFromFile(fileName);
            break;
        }
        case 8: {
            exit(1);
            break;
        }
        }

        cout << "\t\tDo You Want to Continue or Exit [Yes/No] ??";
        cin >> op;

    } while (op == 'y' || op == 'Y');

    return 0;
}

