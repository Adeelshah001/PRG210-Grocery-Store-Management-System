#include <iostream>
#include "interface.h"
#include "fileHandling.h"
#include "customerinterface.h"
#include "managerinterface.h"
using namespace std;

int main() {
    
	if (loadDataFromCsv(csvFile) != 0) 
	{
    	cout << "Failed to load grocery data from CSV file.\n Exiting...\n";
    	return 1;
	}
	int choices=0;
    do {
		cout << "\nWelcome to the Grocery Store Management System\n";
		cout << "----------------------------------------------\n\n";
		cout << "Please select your role or exit:";
        cout << "\n" <<"\n1. Customer\n2. Manager\n 3.Exit\n";
		cout << "Enter your choice: ";
        while (!(cin >> choices))
        {
           cin.clear();
           cin.ignore(1000, '\n');
           cout << "Invalid input. Enter 1-3: ";
        }

        switch (choices) 
        {
           case 1: 
           {
               CustomerInterface customerUI;
               customerUI.showMenu();
               break;
           }
           case 2: 
           {
               ManagerInterface managerUI;
               managerUI.showMenu();
               break;
           }
           case 3:
           {
               cout << "Exiting program...\n";
               break;
           }
           default:
           {
               cout << "Invalid choice\n";
           }
        }

    } while (choices != 3);
	
	if (StoreDepartments != nullptr)
	{
    	delete[] StoreDepartments;
    	StoreDepartments = nullptr; 
	}
    cout << "PRG210 Group Project Setup Successful!" << endl;
    return 0;;
}
