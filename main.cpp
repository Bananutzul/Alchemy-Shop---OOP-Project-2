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

int main() {

    //Code to enable ASNI codes for colors / effects
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | 0x0004);

    Shop test("Alchemy Shop");
    Player player("Horia", 5000.0);

    player.loadFromFile();

    test.addProduct(new SacredIngredient("Phoenix-Ash", 100, 8, "Flame", 75));
    test.addProduct(new CursedIngredient("Medusa's-Eye", 200, 9, 85, "Earth"));
    test.addProduct(new SacredIngredient("Leviathan-Tear", 120, 7, "Oceanic", 60));
    test.addProduct(new CursedIngredient("Stygian-Water", 75, 5, 50, "Myth"));
    test.addProduct(new SacredIngredient("Hero's-Sword", 250, 10, "Holy", 90));
    test.addProduct(new CursedIngredient("Devilish-Horn", 175, 9, 65, "Hellish"));

    Menu menu(player, test);

    menu.startMenu();

    return 0;
}