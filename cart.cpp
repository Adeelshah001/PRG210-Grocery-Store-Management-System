#include "cart.h"
#include "product.h" 
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

static const double TAX_RATE = 0.13;

// Default constructor
Cart::Cart()
{
    items = nullptr;
    quantities = nullptr;
    totalItems = 0;
    totalCost = 0.0;
}

// Copy constructor
Cart::Cart(const Cart& other)
{
    totalItems = other.totalItems;
    totalCost = other.totalCost;

    if (totalItems > 0)
    {
        items = new product[totalItems];
        quantities = new int[totalItems];

        for (int i = 0; i < totalItems; ++i)
        {
            items[i] = other.items[i];
            quantities[i] = other.quantities[i];
        }
    }
    else
    {
        items = nullptr;
        quantities = nullptr;
    }
}

// Assignment operator
Cart& Cart::operator=(const Cart& other)
{
    if (this != &other)
    {
        delete[] items;
        delete[] quantities;

        totalItems = other.totalItems;
        totalCost = other.totalCost;

        if (totalItems > 0)
        {
            items = new product[totalItems];
            quantities = new int[totalItems];

            for (int i = 0; i < totalItems; ++i)
            {
                items[i] = other.items[i];
                quantities[i] = other.quantities[i];
            }
        }
        else
        {
            items = nullptr;
            quantities = nullptr;
        }
    }

    return *this;
}

// Destructor
Cart::~Cart()
{
    delete[] items;
    delete[] quantities;

    items = nullptr;
    quantities = nullptr;
    totalItems = 0;
    totalCost = 0.0;
}

// Find product by name in cart
int Cart::findProductIndex(const char* productName) const
{
    for (int i = 0; i < totalItems; ++i)
    {
        if (strcmp(items[i].getName(), productName) == 0)
        {
            return i;
        }
    }

    return -1;
}

//Recalculate total cost including tax
void Cart::updateTotalCost()
{
    double subtotal = 0.0;

    for (int i = 0; i < totalItems; ++i)
    {
        subtotal += items[i].getPrice() * quantities[i];
    }

    totalCost = subtotal + (subtotal * TAX_RATE);
}

// Resize arrays and append a new product
void Cart::resizeAndAdd(const product& prod, int quantity)
{
    product* tempItems = new product[totalItems + 1];
    int* tempQuantities = new int[totalItems + 1];

    for (int i = 0; i < totalItems; ++i)
    {
        tempItems[i] = items[i];
        tempQuantities[i] = quantities[i];
    }

    tempItems[totalItems] = prod;
    tempQuantities[totalItems] = quantity;

    delete[] items;
    delete[] quantities;

    items = tempItems;
    quantities = tempQuantities;
    totalItems++;
}

// Add items to cart
void Cart::addItem(const product& prod, int quantity)
{
    if (quantity <= 0)
    {
        cout << "Invalid quantity." << "\n";
        return;
    }

    int index = findProductIndex(prod.getName());

    if (index != -1)
    {
        quantities[index] += quantity;
    }
    else
    {
        resizeAndAdd(prod, quantity);
    }

    updateTotalCost();
}

//Print all items in the cart
void Cart::listItems() const
{
    cout << fixed << setprecision(2);
    cout << "\n========================= SHOPPING CART =========================" << "\n";
    cout << left << setw(5) << "No"
        << setw(20) << "Item Name"
        << setw(10) << "Qty"
        << setw(12) << "Price"
        << setw(15) << "Line Total" << endl;

    cout << "-----------------------------------------------------------------" << endl;

    if (isEmpty())
    {
        cout << "No items in the cart..." << "\n";
        cout << "-----------------------------------------------------------------" << "\n";
        return;
    }


    for (int i = 0; i < totalItems; ++i) // loopdisplay all items
    {
        double lineTotal = items[i].getPrice() * quantities[i];
        // display items info in aligned columns
        cout << left << setw(5) << (i + 1)          // item index
             << setw(20) << items[i].getName()     // product name
             << setw(10) << quantities[i]          // quantity
             << setw(12) << items[i].getPrice()    // single price
             << setw(15) << lineTotal              // total price
             << endl;
    }

    cout << "-----------------------------------------------------------------" << "\n";
    cout << right << setw(35) << "Subtotal: $" << setw(10) << getSubtotal() << endl;
    cout << right << setw(35) << "Tax (13%): $" << setw(10) << getTax() << endl;
    cout << right << setw(35) << "Total: $" << setw(10) << getTotalCost() << endl;
    cout << "=================================================================" << "\n";
}

// Checkout and clear cart
void Cart::checkout()
{
    if (isEmpty())
    {
        cout << "No items in the cart" << "\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "Thank you for your purchase" << "\n";
    cout << "Final total: $" << getTotalCost() << "\n";

    clear();
}

// Clear cart contents
void Cart::clear()
{
    delete[] items;
    delete[] quantities;

    items = nullptr;
    quantities = nullptr;
    totalItems = 0;
    totalCost = 0.0;
}

// Check whether cart is empty
bool Cart::isEmpty() const
{
    return totalItems == 0;
}

// Return number of unique item entires in cart
int Cart::getTotalItems() const
{
    return totalItems;
}

// Return subtotal before tax
double Cart::getSubtotal() const
{
    double subtotal = 0.0;

    for (int i = 0; i < totalItems; ++i)
    {
        subtotal += items[i].getPrice() * quantities[i];
    }

    return subtotal;
}

// Return tax amount only
double Cart::getTax() const
{
    return getSubtotal() * TAX_RATE;
}

// Return total cost including tax
double Cart::getTotalCost() const
{
    return totalCost;
}
