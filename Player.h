#pragma once

#include <string>
#include <vector>
#include "Product.h"
#include "Shop.h"
#include "Potion.h"

using namespace std;

class Player {
public:
    string name;
    double balance;
    vector<Product*> inventory;
public: 
    Player();
    Player(string name, double balance);
    Player(const Player& player);
    Player& operator=(const Player& player);
    ~Player();

    void buyProduct(Product* prod);
    Product*& selectProduct(int idx);
    Potion* createPotion(Product* &prod1, Product* &prod2);
    void testPotion(Product* potion);
    void sellPotion(int idx, Shop& shop);
    void displayInventory();
    void clearInventory();

    double getBalance() const;
    void setBalance(double ammount);
    string getName() const;
};