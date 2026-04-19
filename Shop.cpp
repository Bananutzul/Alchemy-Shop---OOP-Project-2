#include "Shop.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Shop::Shop() {
    shopName = "N/A";
}

Shop::Shop(string shopName) {
    this->shopName = shopName;
}

Shop::Shop(const Shop& obj) {
    shopName = obj.shopName;

    for (int i = 0; i < obj.inventory.size(); i++)
        inventory.push_back(obj.inventory[i]->clone()); // evitam slicing
}

Shop& Shop::operator=(const Shop& obj) {
    if (this == &obj)
        return *this;

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
    cout << "Shop Inventory: \n";

    for (int i = 0; i < this->inventory.size(); i++) {
        cout << "Item " << i + 1 << " : " << inventory[i]->getName() << " , " << inventory[i]->calculatePrice() << " gold\n"; 
    }
}

Product* Shop::selectProduct(int idx) {
    return this->inventory[idx - 1];
}

void Shop::itemDescription(int idx) {

    Product* prod = this->inventory[idx - 1]->clone();

    if (dynamic_cast<SacredIngredient*>(prod) != nullptr) {
        cout << "Sacred Ingr\n";
    }else if (dynamic_cast<CursedIngredient*>(prod) != nullptr) {
        cout << "Cursed Ingr\n";
    }else if (dynamic_cast<Potion*>(prod)  != nullptr){
        cout << "Potion\n";
    }else cout << "This isn't a valid item\n";

    delete prod;
}