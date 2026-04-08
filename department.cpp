#define _CRT_SECURE_NO_WARNINGS
#include "department.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// -------------------------------------------------------------
// Helper function: deep-copies another Department object
// Used by both the copy constructor and assignment operator
// -------------------------------------------------------------
void Department::copyFrom(const Department& other)
{
    // Copy department name
    strcpy(departmentName, other.departmentName);

    // Copy number of items
    totalItems = other.totalItems;

    // Deep copy the product array
    if (totalItems > 0)
    {
        items = new product[totalItems];
        for (int i = 0; i < totalItems; i++)
        {
            items[i] = other.items[i];
        }
    }
    else
    {
        items = nullptr;
    }
}

// -------------------------------------------------------------
// Default constructor: creates an empty department
// -------------------------------------------------------------
Department::Department()
{
    departmentName[0] = '\0';  // Empty name
    items = nullptr;           // No products yet
    totalItems = 0;
}

// -------------------------------------------------------------
// Constructor that sets the department name
// -------------------------------------------------------------
Department::Department(const char* name)
{
    // Copy name safely into fixed-size array
    strncpy(departmentName, name, sizeof(departmentName) - 1);
    departmentName[sizeof(departmentName) - 1] = '\0';

    items = nullptr;
    totalItems = 0;
}

// -------------------------------------------------------------
// Copy constructor: deep copy
// -------------------------------------------------------------
Department::Department(const Department& other)
{
    copyFrom(other);
}

// -------------------------------------------------------------
// Assignment operator: deep copy with cleanup of old memory
// -------------------------------------------------------------
Department& Department::operator=(const Department& other)
{
    if (this != &other) // Avoid self-assignment
    {
        delete[] items; // Free old memory
        copyFrom(other);
    }
    return *this;
}

// -------------------------------------------------------------
// Destructor: frees dynamic memory
// -------------------------------------------------------------
Department::~Department()
{
    delete[] items;
    items = nullptr;
    totalItems = 0;
}

// -------------------------------------------------------------
// Sets department name and product list
// Used by CSV loader to populate department data
// -------------------------------------------------------------
void Department::setDepartmentInfo(const char* name, product* products, int count)
{
    // Copy department name
    strncpy(departmentName, name, sizeof(departmentName) - 1);
    departmentName[sizeof(departmentName) - 1] = '\0';

    // Delete old product list if it exists
    delete[] items;

    totalItems = count;

    // Deep copy product array
    if (count > 0)
    {
        items = new product[count];
        for (int i = 0; i < count; i++)
        {
            items[i] = products[i];
        }
    }
    else
    {
        items = nullptr;
    }
}

// -------------------------------------------------------------
// Returns department name
// -------------------------------------------------------------
const char* Department::getDepartmentName() const
{
    return departmentName;
}

// -------------------------------------------------------------
// Returns number of products in this department
// -------------------------------------------------------------
int Department::getTotalItems() const
{
    return totalItems;
}

// -------------------------------------------------------------
// Returns pointer to product array (used by CSV saving)
// -------------------------------------------------------------
product* Department::getProducts() const
{
    return items;
}

// -------------------------------------------------------------
// Adds a new product by resizing the dynamic array
// -------------------------------------------------------------
void Department::addItem(const product& p)
{
    // Create new array with one extra slot
    product* temp = new product[totalItems + 1];

    // Copy existing products
    for (int i = 0; i < totalItems; i++)
    {
        temp[i] = items[i];
    }

    // Add new product at the end
    temp[totalItems] = p;

    // Replace old array
    delete[] items;
    items = temp;

    totalItems++;
}

// -------------------------------------------------------------
// Prints all items in this department
// Used by manager and customer interfaces
// -------------------------------------------------------------
void Department::listItems() const
{
    if (totalItems == 0)
    {
        cout << "No items in this department\n";
        return;
    }
    else
    {
        cout << "---------------------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(5) << "No"
            << setw(20) << "Item Name"
            << setw(12) << "Price"
            << setw(8) << "Qty" << endl;
        cout << "---------------------------------------------" << endl;
    }
    for (int i = 0; i < totalItems; i++)
    {
        cout << left << setw(5) << (i + 1)
            << setw(20) << items[i].getName()
            << setw(12) << items[i].getPrice()
            << setw(8) << items[i].getQuantity()
            << endl;
    }
}
