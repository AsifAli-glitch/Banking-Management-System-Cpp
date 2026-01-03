#include <iostream>
using namespace std;

class Account
{
public:
    int accNo;
    float balance;
    string lastTransaction;
    float lastAmount;

    void create()
    {
        cout << "Enter Account Number: ";
        cin >> accNo;
        balance = 0;
        lastTransaction = "None";
        lastAmount = 0;
    }

    void deposit(float amt)
    {
        balance += amt;
        lastTransaction = "Deposit";
        lastAmount = amt;
    }

    void withdraw(float amt)
    {
        if (amt <= balance)
        {
            balance -= amt;
            lastTransaction = "Withdraw";
            lastAmount = amt;
        }
        else
        {
            cout << "Not enough balance\n";
        }
    }

    void show()
    {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
        cout << "Last Transaction: " << lastTransaction << endl;
        cout << "Amount: " << lastAmount << endl;
    }
};

class Customer
{
public:
    string name;
    Account acc;

    void createCustomer()
    {
        cout << "Enter Name: ";
        cin >> name;
        acc.create();
    }

    void showCustomer()
    {
        cout << "Customer Name: " << name << endl;
        acc.show();
    }
};

int main()
{
    Customer c;

    c.createCustomer();

    c.acc.deposit(3000);
    c.acc.withdraw(1000);

    c.showCustomer();

    return 0;
}
