#include "ManagerInterface.h"
#include<fstream>
#include<cstring>

void ManagerInterface::ShowMenu()
{
    int choice=0;
    while(choice!=5)
    {
        cout<<"1. List Departments\n2. Add Department\n3. Add Item to Department\n4. Save Changes to CSV\n5. Exit"; 
        cout<<"Enter you choice: "; // taking input to try one of these options
        cin>>choice;
        if(choice==1)
        {
            listDepartments();
        }
        else if(choice==2)
        {
            addDepartment();
        }
        else if(choice==3)
        {
            addItem();
        }
        else if(choice==4)
        {
            saveChanges();
        }
        else if(choice==5)
        {
            cout<<"Exiting Manager Menu\n";
        }
        else
        {
            cout<<"Invalid choice, please enter a valid input.\n";
        }
    }

}

void ManagerInterface::listDepartments()//List all departments in the store
{
    if (TotalDepartments == 0)
    {
        cout << "No departments available.\n";
        return;
    }
    for(int i=0;i<TotalDepartments;i++)
    {
        cout<<i+1<<" "<<StoreDepartments[i].getDepartmentName()<<endl;
    }
}

void ManagerInterface::addDepartment()//To adda new department to the store
{
    char deptName[50];
    cout<<"Enter the Department Name: ";
    cin>>deptName;

    Department *newDepartments;
    newDepartments = new Department[TotalDepartments + 1];

    for(int i=0;i < TotalDepartments;i++) // copy old departments into new array
    {
        newDepartments[i]=StoreDepartments[i];
    
    }
    
    //add new department at the end
    newDepartments[TotalDepartments].setDepartmentInfo(deptName,nullptr,0);

    delete[] StoreDepartments; // delete old array
    StoreDepartments =newDepartments;//point to new array
    TotalDepartments++;//increase department count

    cout<<"Department added successfully"<<endl;

}
void ManagerInterface::addItem()//To add a new item to a specific department
{
    listDepartments();// to list depratment before selecting it
    cout<<"Select a department: \n";
    
    int deptChoice;
    cout<<"Enter a department number: ";
    cin>> deptChocie;

    if(deptChoice<1 || deptChoice > TotalDepartments)
    {
        Cout<<"Invalid department number. Returning to main menu.\n";
        return;
    }

    char itemName[100];
    double price;
    int quantity;

    cout<<"Enter Item Name: ";
    cin>>itemName;
    cout<<"Enter Price:";
    cin>>price;
    cout <<"Enter Quantity:";
    cin>> quantity;

    product newItem(itemName, price,quantity);
    StoreDepartments[deptChoice-1].addItem(newItem);

    cout<<"Item added successfully.\n";
}

void ManagerInterface::saveChanges()//Save changes to CSV file
{
    if(saveDataToCsv(csvFile)==0)
    {
        cout<<"Data saved successfully to "<<csvFile<<endl;
    }
    else
    {
        cout<<"Error saving data to "<<csvFile<<endl;
    }
}

