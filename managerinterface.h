#include "interface.h"
#include "department.h"
#include "fileHandling.h"
#include "product.h"
#include <iostream>
using namespace std;

class ManagerInterface : public Interface
{
private:
    void listDepartments();
    void addDepartment();
    void addItem();
    void saveChanges();

public:
    void showMenu();  // override base class menu
};
