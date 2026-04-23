#include "Shop.h"
#include "Player.h"
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


using namespace std;

int main() {

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | 0x0004);

    Shop test("Alchemy Shop");
    Player player("Horia", 5000.0);

    test.addProduct(new SacredIngredient("Phoenix-Ash", 100, 8, "Flame", 75));
    test.addProduct(new CursedIngredient("Medusa's-Eye", 200, 9, 85, "Earth"));
    test.addProduct(new SacredIngredient("Leviathan-Tear", 120, 7, "Oceanic", 60));
    test.addProduct(new CursedIngredient("Stygian-Water", 75, 5, 50, "Myth"));
    test.addProduct(new SacredIngredient("Hero's-Sword", 250, 10, "Holy", 90));
    test.addProduct(new CursedIngredient("Devilish-Horn", 175, 9, 65, "Hellish"));

    player.buyProduct(test.selectProduct(1));
    player.buyProduct(test.selectProduct(2));
    player.buyProduct(test.selectProduct(3));
    player.buyProduct(test.selectProduct(4));
    player.buyProduct(test.selectProduct(5));
    player.buyProduct(test.selectProduct(6));

    player.displayInventory();

    player.inventory.push_back(player.createPotion(player.selectProduct(3), player.selectProduct(1)));

    player.testPotion(player.selectProduct(5));

    return 0;
}