#include<iostream>
#include<string>
using namespace std;

class Bank
{
private:
    int acno;
    string name;
    float balance;
    int amt;
    string transaction[20];
    int t = 0;

public:

    void openAccount()
    {
        cout << "Enter the Account no: ";
        cin >> acno;

        cout << "Enter the customer name: ";
        cin >> name;

        cout << "Enter the initial balance: ";
        cin >> balance;
    }

    void showAccount()
    {
        cout << "Account No: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposite()
    {
        cout << "Enter amount to deposit: ";
        cin >> amt;

        if(amt <= 0)
        {
            cout << "Invalid amount" << endl;
        }
        else
        {
            balance += amt;

            transaction[t] = "Deposit successful: " + to_string(amt);
            t++;

            cout << "Balance after deposit: " << balance << endl;
        }
    }

    void withdrwal()
    {
        cout << "Enter amount to withdraw: ";
        cin >> amt;

        if(amt <= 0)
        {
            cout << "Invalid amount" << endl;
        }
        else if(amt <= balance)
        {
            balance -= amt;

            transaction[t] = "Withdrawal successful: " + to_string(amt);
            t++;

            cout << "Balance after withdrawal: "<< balance << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    void Transaction()
    {
        cout << "\nTransaction History" << endl;

        if(t == 0)
        {
            cout << "No transaction yet" << endl;
        }
        else
        {
            for(int i = 0; i < t; i++)
            {
                cout << i + 1 << ". " << transaction[i] << endl;
            }
        }
    }

    bool search(int an)
    {
        if(acno == an)
        {
            return true;
        }

        return false;
    }
};


int main()
{
    Bank b[2];

    // Opening 2 accounts
    cout << "===== OPEN ACCOUNTS =====" << endl;

    for(int i = 0; i < 2; i++)
    {
        cout << "\nAccount " << i + 1 << endl;
        b[i].openAccount();
    }

    int choice;
    int an;
    int index;

    do
    {
        cout << "\n\n========== BANK MENU ==========" << endl;
        cout << "1. Show Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transaction History" << endl;
        cout << "5. Search Account" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if(choice >= 1 && choice <= 5)
        {
            cout << "Enter Account No: ";
            cin >> an;

            index = -1;

            for(int i = 0; i < 2; i++)
            {
                if(b[i].search(an))
                {
                    index = i;
                    break;
                }
            }

            if(index == -1)
            {
                cout << "Account not found!" << endl;
                continue;
            }
        }

        switch(choice)
        {
            case 1:
                b[index].showAccount();
                break;

            case 2:
                b[index].deposite();
                break;

            case 3:
                b[index].withdrwal();
                break;

            case 4:
                b[index].Transaction();
                break;

            case 5:
                cout << "Account found!" << endl;
                b[index].showAccount();
                break;

            case 6:
                cout << "Thank you for using the Bank System!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}