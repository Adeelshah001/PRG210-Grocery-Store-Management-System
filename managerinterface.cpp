#include "managerinterface.h"
#include <fstream>
#include <cstring>

using namespace std;

void ManagerInterface::showMenu()
{
    int choice = 0;

    while (choice != 5)
    {
        cout << "\nManager Menu\n";
        cout << "---------------------\n";
        cout << "1. List Departments\n";
        cout << "2. Add Department\n";
        cout << "3. Add Item to Department\n";
        cout << "4. Save Changes to CSV\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter 1-5: ";
        }

        if (choice == 1)
        {
            listDepartments();
        }
        else if (choice == 2)
        {
            addDepartment();
        }
        else if (choice == 3)
        {
            addItem();
        }
        else if (choice == 4)
        {
            saveChanges();
        }
        else if (choice == 5)
        {
            cout << "Exiting Manager Menu\n";
        }
        else
        {
            cout << "Invalid choice. Please enter 1-5.\n";
        }
    }
}

void ManagerInterface::listDepartments()
{
    if (TotalDepartments == 0)
    {
        cout << "No departments available.\n";
        return;
    }

    cout << "\nDepartments in the Store:\n";
    cout << "-------------------------\n";

    for (int i = 0; i < TotalDepartments; i++)
    {
        cout << i + 1 << ". " << StoreDepartments[i].getDepartmentName() << endl;
    }
}

void ManagerInterface::addDepartment()
{
    char deptName[50];

    cout << "Enter the Department Name: ";

    // Clear leftover newline before getline
    cin.ignore(1000, '\n');
    cin.getline(deptName, 50);

    if (deptName[0] == '\0')
    {
        cout << "Department name cannot be empty.\n";
        return;
    }

    // Create a larger department array
    Department* newDepartments = new Department[TotalDepartments + 1];

    // Copy old departments
    for (int i = 0; i < TotalDepartments; i++)
    {
        newDepartments[i] = StoreDepartments[i];
    }

    // Add new department at the end
    newDepartments[TotalDepartments].setDepartmentInfo(deptName, nullptr, 0);

    // Replace old array
    delete[] StoreDepartments;
    StoreDepartments = newDepartments;
    TotalDepartments++;

    cout << "Department added successfully.\n";
}

void ManagerInterface::addItem()
{
    if (TotalDepartments == 0)
    {
        cout << "No departments available.\n";
        return;
    }

    listDepartments();

    int deptChoice;
    cout << "Enter a department number: ";

    while (!(cin >> deptChoice))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid department number: ";
    }

    if (deptChoice < 1 || deptChoice > TotalDepartments)
    {
        cout << "Invalid department number. Returning to main menu.\n";
        return;
    }

    char itemName[100];
    double price;
    int quantity;

    cout << "Enter Item Name: ";
    cin.ignore(1000, '\n');
    cin.getline(itemName, 100);

    if (itemName[0] == '\0')
    {
        cout << "Item name cannot be empty.\n";
        return;
    }

    cout << "Enter Price: ";
    while (!(cin >> price))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid price: ";
    }

    cout << "Enter Quantity: ";
    while (!(cin >> quantity))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid quantity: ";
    }

    product newItem(itemName, price, quantity);
    StoreDepartments[deptChoice - 1].addItem(newItem);

    cout << "Item added successfully.\n";
}

void ManagerInterface::saveChanges()
{
    if (saveDataToCsv(csvFile) == 0)
    {
        cout << "Data saved successfully to " << csvFile << "\n";
    }
    else
    {
        cout << "Error saving data to " << csvFile << "\n";
    }
}