#include "Shop.h"
#include "Player.h"
#include "Menu.h"
#include "Product.h"
#include "SacredIngredient.h"
#include "CursedIngredient.h"
#include "Potion.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOUSER
#define BYTE_DEFINED
#include <windows.h>

#include "Exceptions.h"


using namespace std;

const string FILENAME_SHOP = "inventory_shop.text";

int main() {

    //Code to enable ASNI codes for colors / effects
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | 0x0004);

    Shop test("Alchemy Shop");
    Player player;

    player.loadFromFile();
    test.loadFromFile(FILENAME_SHOP);

    if (player.getName().empty())
        cin >> player, player.saveToFile();

    Menu menu(player, test);

    menu.startMenu();

    return 0;
}