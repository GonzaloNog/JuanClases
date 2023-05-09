#include <iostream>
#include <string>


using namespace std;

class Account {
private:
    int accountNumber;
    string nameCustomer;
    double balance;

public:
    Account(int accountNumber, string nameCustomer, double balance) {
        this->accountNumber = accountNumber;
        this->nameCustomer = nameCustomer;
        this->balance = balance;
    }

    void depositar(double amount) {
        balance += amount;
    }

    void retirar(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "No cuentas con el dinero suficiente" << endl;
    }

    void mostrarInformacion() {
        cout << "Numero de cuenta: " << accountNumber << endl;
        cout << "Nombre del titular: " << nameCustomer << endl;
        cout << "Saldo: " << balance << endl;
    }

    void nameCustomerChange(string newName) {
        nameCustomer = newName;
    }

    //Set y Get

    
    string getName() {
        return nameCustomer;
    }
    int getAccount() {
        return accountNumber;
    }
};

int main() {
    Account account1(123456, "Juan PÃ©rez", 1000.0);

    account1.depositar(500.0);
    account1.retirar(1700.0);
    //account1.nameCustomerChange("hola");

    account1.mostrarInformacion();

    return 0;
}
