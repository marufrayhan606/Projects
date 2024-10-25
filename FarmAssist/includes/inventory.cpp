#include "inventory.h"
using namespace std;

void viewStock() {
    system("cls");
    vector<Crop> crops = loadInventory();
    cout << left << setw(20) << "Name" << setw(10) << "Stock" << setw(15) << "Price per kg (tk)" << endl;
    cout << "---------------------------------------------------" << endl;
    for (const auto& crop : crops) {
        cout << left << setw(20) << crop.name << setw(10) << crop.stock << setw(15) << crop.pricePerUnit << endl;
    }
    cout << "---------------------------------------------------" << endl;
}

vector<Crop> loadInventory() {
    vector<Crop> crops;
    ifstream file("inventory.csv");
    if (!file.is_open()) {
        cout << "Error opening inventory file." << endl;
        return crops;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Crop crop;
        string stockStr, priceStr;

        getline(ss, crop.name, ',');
        getline(ss, stockStr, ',');
        getline(ss, priceStr, ',');

        crop.stock = stoi(stockStr);
        crop.pricePerUnit = stod(priceStr);

        crops.push_back(crop);
    }
    file.close();
    return crops;
}