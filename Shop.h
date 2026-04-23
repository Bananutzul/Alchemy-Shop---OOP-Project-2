#pragma once

#include "SacredIngredient.h"
#include "CursedIngredient.h"
#include "Potion.h"
#include <string>
#include <vector>

using namespace std;

class Shop {
private:
    vector<Product*> inventory;
    string shopName;
public:
    Shop();
    Shop(string shopName);
    Shop(const Shop& obj);
    Shop& operator=(const Shop& obj);
    ~Shop();
    
    void addProduct(Product* prod);
    Product* selectProduct(int idx);
    void displayInventory();
    void itemDescription(int idx);
    const vector<Product*>& getInventory() const;
};