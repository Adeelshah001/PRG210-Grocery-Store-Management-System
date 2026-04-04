#include "interface.h"
#include <iostream>
using namespace std;

int Interface::getValidChoice(int min, int max)
{
    int choice ;
    while( true)
    {
        cin>>choice;
        if(choice >= min && choice <= max)// basic range check 
        {
            return choice;
        }
        else
        {
            cout<<"Invalid input, Please enter again:";
        }

    }
}
