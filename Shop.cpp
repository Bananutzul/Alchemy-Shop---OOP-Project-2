#include "Shop.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

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
    cout << "---Shop Inventory---\n";

    if (this->inventory.size() == 0) {
        cout << "EMPTY\n";
    }else {
        for (int i = 0; i < this->inventory.size(); i++) {
            cout << "Item " << i + 1 << " : " << inventory[i]->getName() << " , " << inventory[i]->calculatePrice() << " gold  ";
            cout << "Quality : " << this->inventory[i]->getQuality() << "  ";

            auto s = dynamic_cast<SacredIngredient*>(inventory[i]);
            auto c = dynamic_cast<CursedIngredient*>(inventory[i]);
            auto p = dynamic_cast<Potion*>(inventory[i]);

            if (s) {
                cout << "Type : Sacred; Divine Level: " << s->getDivineLevel() << "\n";
            }else if (c) {
                cout << "Type : Cursed; Curse Level: " << c->getCurseLevel() << "\n";
            }else if (p) {
                cout << "Type : Potion; Test for effect!\n";
            }
        }
    }
}

Product* Shop::selectProduct(int idx) {
    return this->inventory[idx];
}

void Shop::itemDescription(int idx) {

    Product* prod = this->inventory[idx]->clone();

    if (dynamic_cast<SacredIngredient*>(prod) != nullptr) {
        cout << "Sacred Ingr\n";
    }else if (dynamic_cast<CursedIngredient*>(prod) != nullptr) {
        cout << "Cursed Ingr\n";
    }else if (dynamic_cast<Potion*>(prod)  != nullptr){
        cout << "Potion\n";
    }else cout << "This isn't a valid item\n";

    delete prod;
}

const vector<Product*>& Shop::getInventory() const {
    return this->inventory;
}
