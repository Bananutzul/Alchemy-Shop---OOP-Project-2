#pragma once
#include "Player.h"
#include "Shop.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Menu {
private:
    Player player;
    Shop shop;
public:
    Menu(Player player, Shop shop);

    void startMenu();
};
