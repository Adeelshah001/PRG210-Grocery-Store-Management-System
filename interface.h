#pragma once
class Interface
{
    public:
        virtual void showMenu()=0;
        int getValidChoice(int min, int max);
};

