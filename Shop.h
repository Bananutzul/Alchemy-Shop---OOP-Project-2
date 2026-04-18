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
    double balance;
    string shopName;
public:
    Shop();
    Shop(double balance, string shopName);
    Shop(const Shop& obj);
    Shop& operator=(const Shop& obj);
    ~Shop();
    
    void addProduct(Product* prod);
    void buyProduct();
    void modifyBalance(double ammount);
    void createPotion();
    void testPotion();

    void showInventory() const;
};