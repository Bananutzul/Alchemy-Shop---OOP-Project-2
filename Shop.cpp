#include "Shop.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Shop::Shop() {
    balance = 0.0;
    shopName = "N/A";
}

Shop::Shop(double balance, string shopName) {
    this->balance = balance;
    this->shopName = shopName;
}

Shop::Shop(const Shop& obj) {
    balance = obj.balance;
    shopName = obj.shopName;

    for (int i = 0; i < obj.inventory.size(); i++)
        inventory.push_back(obj.inventory[i]->clone()); // evitam slicing
}

Shop& Shop::operator=(const Shop& obj) {
    if (this == &obj)
        return *this;

    balance = obj.balance;
    shopName = obj.shopName;

    for (int i = 0; i < inventory.size(); i++)
        delete inventory[i];

    inventory.clear();

    for (int i = 0; i < obj.inventory.size(); i++)
        inventory.push_back(obj.inventory[i]->clone());

    return *this;
}

Shop::~Shop() {
    for (int i = 0; i < inventory.size(); i++)
        delete inventory[i];

    inventory.clear();
}

void Shop::addProduct(Product* prod) {
    inventory.push_back(prod->clone());
}

void Shop::displayInventory() {
    cout << "Inventory: \n";

    for (int i = 0; i < this->inventory.size(); i++) {
        cout << "Item " << i + 1 << " : " << inventory[i]->getName() << " , " << inventory[i]->calculatePrice() << " gold\n"; 
    }
}

void Shop::createPotion(int idx1, int idx2) { //function that creates a potion from 2 ingredients in inventory
    
}