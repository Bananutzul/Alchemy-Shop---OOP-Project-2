#pragma once

#include <string>
#include <vector>
#include "Product.h"

using namespace std;

class Player {
private:
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
    void createPotion(int idx1, int idx2);
    void testPotion(Product* potion);
    void sellPotion(int idx);
    void displayInventory();

    double getBalance() const;
    void setBalance(double ammount);
    string getName() const;
};