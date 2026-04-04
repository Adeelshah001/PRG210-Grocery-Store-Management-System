#include <iostream>
#include "interface.h"
#include "fileHandling.h"
#include "customerinterface.h"
#include "managerinterface.h"
using namespace std;

int main() {
    Interface* ui = nullptr;
    int choices;
    do {
		cout << "Welcome to the Grocery Store Management System\n";
		cout << "----------------------------------------------\n\n";
		cout << "Please select your role or exit:";
        cout << "\n" <<"\n1. Customer\n2. Manager\n 3.Exit\n";
        cin >> choices;
        if(choices==1){
            ui = new CustomerInterface();
            ui->showMenu();
        }
        else if(choices == 2){
            ui = new ManagerInterface();
            ui->showMenu();
		}else
        {
            break;
        }
        delete ui;

    } while (choices != 3);
	delete[] StoreDepartments;
    cout << "PRG210 Group Project Setup Successful!" << endl;
    return 0;;
}
