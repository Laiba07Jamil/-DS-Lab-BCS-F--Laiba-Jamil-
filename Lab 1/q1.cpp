/*Q1. Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named
account1. Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
an initial balance of $1000. Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new
BankAccount object named account3 using the copy constructor. Deduct $200 from
account3 and print out its balance. Also, print out the balance of account2 to ensure it
hasn't been affected by the transaction involving account3.*/

#include <iostream>
using namespace std;

class BankAccount{
    private:
    int *balance;
    public:
    BankAccount(){
        balance = new int;
        *(this->balance) = 500;
    }

    BankAccount(int bal){
        balance = new int;
        *(this->balance) = bal;
    }

    BankAccount(const BankAccount &other){
        balance = new int;
        *(this->balance) = *(other.balance);
    }

    void withdraw(int amount){
        if(*balance >= amount){
            *balance -= amount;
        }
        else{
            cout << "Insufficient balance" << endl;
        }
    }

    int getbalance(){
        return *balance;
    }

    ~BankAccount(){
        delete balance;
    }
};

int main(){
    BankAccount account1;
    cout << "Balance of account 1 = $" << account1.getbalance() << endl;

    BankAccount account2(1000);
    cout << "Balance of account 2 = $" << account2.getbalance() << endl;
    
    BankAccount account3(account2);
    cout << "Balance of account 3 = $" << account3.getbalance() << endl;
    
    account3.withdraw(200);
    cout << "After deduction Balance of account 3 = $" << account3.getbalance() << endl;
    
    cout << "Balance of account 2 = $" << account2.getbalance() << endl;

    return 0;

}

