#include <iostream>
#include "crops.h"
#include "livestock.h"
using namespace std;

void guest()
{
    system("cls");
    cout << "Welcome !!" << endl;
    cout << "--------------------------------" << endl; 
    cout << "You are now browsing as a guest" << endl;
    cout << "Please select an option" << endl;
    cout << "1. Crops" << endl;
    cout << "2. Livestock" << endl;
    cout << "3. Exit" << endl;

    int choice;

    do
    {
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            crops();
            break;
        case 2:
            livestock();
            break;
        case 3:
            return;
            break;
        default:
            cout << "Invalid choice. Please try again" << endl;
            break;
        }

    } while (!(choice >= 1 && choice <= 3));
}