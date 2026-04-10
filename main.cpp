#include <iostream>
#include "interface.h"
#include "fileHandling.h"
#include "customerinterface.h"
#include "managerinterface.h"

using namespace std;

int main()
{
    // Load grocery data from CSV file once at program start
    if (loadDataFromCsv(csvFile) != 0)
    {
        cout << "Failed to load grocery data from CSV file.\n";
        cout << "Program will start with empty store data.\n";
    }

    int choice = 0;

    do
    {
        cout << "\nWelcome to the Grocery Store Management System\n";
        cout << "----------------------------------------------\n\n";
        cout << "Please select your role or exit:\n";
        cout << "1. Customer\n";
        cout << "2. Manager\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter 1-3: ";
        }

        switch (choice)
        {
        case 1:
        {
            // Customer menu
            CustomerInterface customerUI;
            customerUI.showMenu();
            break;
        }
        case 2:
        {
            // Manager menu
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
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            break;
        }
        }

    } while (choice != 3);

    // Clean up department array before program ends
    if (StoreDepartments != nullptr)
    {
        delete[] StoreDepartments;
        StoreDepartments = nullptr;
    }

    cout << "Program ended successfully.\n";
    return 0;
}