#include <iostream>
using namespace std;

int main() {
    Interface* ui = nullptr;
    int choices;
    do {
        cout << "\n" <<"\n1. Customer\n2. Manager\n 3.Exit\n";
        cin >> choices;
        if(choices==1){
            ui = new CustomerInterface();
            ui->showMenu();
        }
        else if(choices == 2){
            ui = new ManagerInterface();
            ui->showMenu();
		}else
        {
            break;
        }
        delete ui;

    } while (choices != 3);
	delete[] StoreDeoartments;
    cout << "PRG210 Group Project Setup Successful!" << endl;
    return 0;;
}
