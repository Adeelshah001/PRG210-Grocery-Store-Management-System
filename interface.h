#ifndef INTERFACE_H
#define INTERFACE_H
class Interface
{
    public:
        virtual void showMenu()=0;
        int getValidChoice(int min, int max);
};
#endif // INTERFACE_H
