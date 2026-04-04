#pragma once
#include "interface.h"
#include "department.h"
#include "cart.h"

using namespace std;

class CustomerInterface : public Interface
{
private:
    Cart shoppingCart;

    void showCartMenu();
    void browseDepartments();

public:
    void showMenu();  // override base class menu
};
