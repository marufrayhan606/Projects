#ifndef MARKETPLACE_H
#define MARKETPLACE_H
#include "inventory.h"

void market();
void addToCart(const Crop& crop, int quantity);
void viewCart();
void placeOrder();


#endif // MENU_H