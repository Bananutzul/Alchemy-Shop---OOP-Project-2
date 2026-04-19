#include "Player.h"
#include "Potion.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Player::Player() {
    name = "N/A";
    balance = 0;
}

Player::Player(string name, double balance) {
    this->name = name;
    this->balance = balance;
}

Player::Player(const Player& player) {
    name = player.name;
    balance = player.balance;

    for (int i = 0; i < player.inventory.size(); i++)
        inventory.push_back(player.inventory[i]->clone());
}

Player& Player::operator=(const Player& player) {
    if (this == &player)
        return *this;

    name = player.name;
    balance = player.balance;

    for (Product* item : inventory) 
        delete item;

    inventory.clear();

    for (Product* item : player.inventory)
        inventory.push_back(item->clone());

        return *this;
}   

Player::~Player() {
    for (Product* item : inventory)
        delete item;

    inventory.clear();
}

double Player::getBalance() const {
    return this->balance;
}

string Player::getName() const {
    return this->name;
}

void Player::setBalance(double ammount) {
    this->balance += ammount;
}


void Player::buyProduct(Product* prod) {
    double price = prod->calculatePrice();
    double curr_balance = this->getBalance();

    if (prod == nullptr) {
        cout << "Invalid product!\n";
        
        return;
    }

    if (curr_balance < price) {
        cout << "You don't have enough gold coins to buy this product!\n";

        return;
    }else {
        this->inventory.push_back(prod->clone());
        
        this->setBalance(price * -1);
    }

}

void Player::displayInventory() {
        cout << this->getName() << "'s Inventory: \n";

    for (int i = 0; i < this->inventory.size(); i++) {
        cout << "Item " << i + 1 << " : " << inventory[i]->getName() << " , " << inventory[i]->calculatePrice() << " gold\n"; 
    }
}