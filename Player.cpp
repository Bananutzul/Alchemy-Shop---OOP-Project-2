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
        cout << inventory[i]->getName() << '\n';
    }
}

Potion* Player::createPotion(Product* &prod1, Product* &prod2) {

    double sacred_score = 0, cursed_score = 0;
    int avgQuality = (prod1->getQuality() + prod2->getQuality()) / 2;
    int avgBasePrice = (prod1->calculatePrice() + prod2->calculatePrice()) / 2.0;
    string potion_name = "Potion of " + prod1->getName() + " and " + prod2->getName();
    string sacred_essence = "Neutral", cursed_essence = "Neutral";

    SacredIngredient* s1 = dynamic_cast<SacredIngredient*>(prod1);
    CursedIngredient* c1 = dynamic_cast<CursedIngredient*>(prod1);
    SacredIngredient* s2 = dynamic_cast<SacredIngredient*>(prod2);
    CursedIngredient* c2 = dynamic_cast<CursedIngredient*>(prod2);

    if (s1 != nullptr)
        sacred_score += s1->addToPotion();
    if (c1 != nullptr)
        cursed_score += c1->addToPotion();
    if (s2 != nullptr)
        sacred_score += s2->addToPotion();
    if (c2 != nullptr)
        cursed_score += c2->addToPotion();

    Potion* temp = new Potion(potion_name, avgBasePrice, avgQuality, sacred_score, sacred_essence, cursed_score, cursed_essence);

    delete prod1;
    delete prod2;

    prod1 = nullptr;
    prod2 = nullptr;

    this->clearInventory();

    return temp;
}

Product*& Player::selectProduct(int idx) {
    return this->inventory[idx - 1];
}

void Player::clearInventory() {
    bool stop = false;

    while (!stop) {
        stop = true;

        for (int i = 0; i < this->inventory.size(); i++) {
            if (inventory[i] == nullptr) {
                inventory.erase(inventory.begin() + i);
                stop = false;
                break;
            }
        }
    }
}