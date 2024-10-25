#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "admin.h"

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
    int choice;
    do {
        cout << "Admin Panel\n";
        cout << "1. View Stock\n";
        cout << "2. Manage Stock\n";
        cout << "3. Exit\n";
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
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 3);
}

