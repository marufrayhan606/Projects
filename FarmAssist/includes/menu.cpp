// Add your includes and function definitions here

#include <iostream>
#include <fstream>
#include <string>

#include "menu.h"
#include "guest.h"
using namespace std;

void homeLayout()
{
    system("cls");
    cout << "*****************************************" << endl;
    cout << "*\t\tFarmAssist\t\t*" << endl;
    cout << "*****************************************" << endl;

    cout << "Welcome to FarmAssist" << endl;
    cout << "Please select an option" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Continue as Guest" << endl;
    cout << "4. Exit" << endl;

    int choice;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:

            if (loginUser())
            {
                cout << "Login successfull!" << endl;
                break;
            }
            else
            {
                cout << "Login failed. Please try again." << endl;
                loginUser();
            }
            break;
        case 3:
            guest();
            break;
        case 4:
            return;
            break;
        default:
            cout << "Invalid choice. Please try again" << endl;
            break;
        }

    } while (!(choice >= 1 && choice <= 4));
}

void registerUser()
{
    system("cls");
    cin.ignore();

    string username, password;
    cout << "Enter a username: ";
    getline(cin, username);
    cout << "Enter a password: ";
    getline(cin, password);

    ofstream file;
    file.open("users.csv", ios::app);
    file << username << "," << password << endl;
    file.close();
    system("cls");
    cout << "User registered successfully!" << endl;
    homeLayout();
}

bool loginUser()
{
    system("cls");
    string username, password;
    cin.ignore();
    cout << "Enter your username: ";
    getline(cin, username);
    cout << endl;
    cout << "Enter your password: ";
    getline(cin, password);

    ifstream file;
    file.open("users.csv");
    string storedUsername, storedPassword;
    while (getline(file, storedUsername, ',') && getline(file, storedPassword, '\n'))
    {
        if (storedUsername == username && storedPassword == password)
        {
            return true;
        }
    }
    return false;
}