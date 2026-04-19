#include "Shop.h"
#include "Player.h"
#include "Product.h"
#include "SacredIngredient.h"
#include "CursedIngredient.h"
#include "Potion.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    Shop test("Alchemy Shop");
    Player player("Horia", 500.0);

    test.addProduct(new SacredIngredient("Lunar Essence", 20.0, 8, "Lunar", 10));
    test.addProduct(new Potion("Prod", 15.0, 7, 10, "Solar", 8, "Hell", "Fire Potion"));

    test.displayInventory();
    player.displayInventory();
    player.buyProduct(test.selectProduct(1));
    player.displayInventory();
    test.itemDescription(1);
}