
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;



struct Crop {
    string name;
    int stock;
    double pricePerUnit;
};

struct CartItem {
    Crop crop;
    int quantity;
};



vector<Crop> loadInventory();
void viewStock();

void addToCart(const Crop& crop, int quantity);
void viewCart();
void placeOrder();


#endif // INVENTORY_H
