#include "Shop.h"
#include "Player.h"
#include "Product.h"
#include "SacredIngredient.h"
#include "CursedIngredient.h"
#include "Potion.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void loadInventory(const string& filename, Shop& shop) {
    ifstream fin(filename);

    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        string type, name, essence;
        double basePrice, essenceLevel;
        int quality;

        if (ss >> type >> name >> basePrice >> quality >> essence >> essenceLevel) {
            if (type == "Sacred") {
                shop.addProduct(new SacredIngredient(name, basePrice, quality, essence, essenceLevel));
            }else if (type == "Cursed"){
                shop.addProduct(new CursedIngredient(name, basePrice, quality, essenceLevel, essence));
            }else cout << "Not a valid item!\n";
        }

        cout << "Product read\n";
    }

    fin.close();
}

int main() {

    Shop test("Alchemy Shop");
    Player player("Horia", 500.0);

    loadInventory("input.txt", test);

    test.displayInventory();
    // player.displayInventory();
    // player.buyProduct(test.selectProduct(1));
    // player.displayInventory();
    // test.itemDescription(1);
}