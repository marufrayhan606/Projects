#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "admin.h"
#include "menu.h"

using namespace std;

void saveInventory(const vector<Crop>& crops) {
    ofstream file("inventory.csv");
    if (!file.is_open()) {
        cout << "Error opening inventory file for writing." << endl;
        return;
    }

    for (const auto& crop : crops) {
        file << crop.name << "," << crop.stock << "," << crop.pricePerUnit << endl;
    }
    file.close();
}


void manageStock() {
    vector<Crop> crops = loadInventory();
    string cropName;
    cout << "Enter the crop name to update: ";
    cin.ignore();
    getline(cin, cropName);

    bool found = false;
    for (auto& crop : crops) {
        if (crop.name == cropName) {
            cout << "Enter new stock quantity: ";
            cin >> crop.stock;
            cout << "Enter new price per unit: ";
            cin >> crop.pricePerUnit;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Crop not found in inventory." << endl;
    } else {
        saveInventory(crops);
        cout << "Inventory updated successfully." << endl;
    }
}

void adminPanel() {

    system("cls");

    int choice;
    do {
        cout << "***********" << endl;
        cout << "Admin Panel" << endl;
        cout << "1. View Stock" << endl;
        cout << "2. Manage Stock" << endl;
        cout << "3. Logout" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewStock();
            break;
        case 2:
            viewStock();
            manageStock();
            break;
        case 3:
            homeLayout();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);
}

