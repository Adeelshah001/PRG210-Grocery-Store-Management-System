#include "customerinterface.h"
#include "fileHandling.h"
#include "department.h"
#include "product.h"
#include <iostream>

using namespace std;

void CustomerInterface::showMenu()
{
    int choice = 0;

    while (choice != 3)
    {
        cout << "\nCustomer Menu\n";
        cout << "1. Show Cart\n";
        cout << "2. Browse Departments\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter 1-3: ";
        }

        if (choice == 1)
        {
            showCartMenu();
        }
        else if (choice == 2)
        {
            browseDepartments();
        }
        else if (choice == 3)
        {
            cout << "Exiting Customer Menu...\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// Cart menu
void CustomerInterface::showCartMenu()
{
    int choice = 0;

    while (choice != 3)
    {
        cout << "\nCart Menu\n";
        cout << "1. List Items\n";
        cout << "2. Checkout\n";
        cout << "3. Return to Main Menu\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter 1-3: ";
        }

        if (choice == 1)
        {
            shoppingCart.listItems();
        }
        else if (choice == 2)
        {
            shoppingCart.checkout();
        }
        else if (choice != 3)
        {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// Browse departments and add items
void CustomerInterface::browseDepartments()
{
    if (TotalDepartments == 0)
    {
        cout << "No departments available.\n";
        return;
    }

    int depChoice = 0;

    while (true)
    {
        cout << "\nDepartments:\n";
        for (int i = 0; i < TotalDepartments; i++)
        {
            cout << (i + 1) << ". " << StoreDepartments[i].getDepartmentName() << "\n";
        }

        cout << "0. Return to Main Menu\n";
        cout << "Select department number: ";

        while (!(cin >> depChoice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a valid department number: ";
        }

        if (depChoice == 0)
        {
            break;
        }

        if (depChoice < 1 || depChoice > TotalDepartments)
        {
            cout << "Invalid department number.\n";
            continue;
        }

        Department& dep = StoreDepartments[depChoice - 1];
        dep.listItems();

        int itemChoice = 0;
        cout << "Enter item number to add to cart (0 to go back): ";

        while (!(cin >> itemChoice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a valid item number: ";
        }

        if (itemChoice == 0)
        {
            continue;
        }

        if (itemChoice < 1 || itemChoice > dep.getTotalItems())
        {
            cout << "Invalid item number.\n";
            continue;
        }

        int quantity;
        cout << "Enter quantity: ";

        while (!(cin >> quantity))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a valid quantity: ";
        }

        product p = dep.getProducts()[itemChoice - 1];
        shoppingCart.addItem(p, quantity);

        cout << "Item added to cart.\n";
    }
}