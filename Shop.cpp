#include "Shop.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Exceptions.h"

using namespace std;

const string FILENAME = "inventory_shop.text";

Shop::Shop() {
    shopName = "N/A";
}

Shop::Shop(string shopName) {
    this->shopName = shopName;
}

Shop::Shop(const Shop& obj) {
    shopName = obj.shopName;

    for (int i = 0; i < obj.inventory.size(); i++)
        inventory.push_back(obj.inventory[i]->clone()); // evitam slicing
}

Shop& Shop::operator=(const Shop& obj) {
    if (this == &obj)
        return *this;

    shopName = obj.shopName;

    for (int i = 0; i < inventory.size(); i++)
        delete inventory[i];

    inventory.clear();

    for (int i = 0; i < obj.inventory.size(); i++)
        inventory.push_back(obj.inventory[i]->clone());

    return *this;
}

Shop::~Shop() {
    for (int i = 0; i < inventory.size(); i++)
        delete inventory[i];

    inventory.clear();
}

void Shop::addProduct(Product* prod) {
    inventory.push_back(prod->clone());
}

void Shop::displayInventory() {
    cout << "---Shop Inventory---\n";

    if (this->inventory.size() == 0) {
        cout << "EMPTY\n";
    }else {
        for (int i = 0; i < this->inventory.size(); i++) {
            cout << "Item " << i + 1 << " : " << inventory[i]->getName() << " , " << inventory[i]->calculatePrice() << " gold  ";
            cout << "Quality : " << this->inventory[i]->getQuality() << "  ";

            auto s = dynamic_cast<SacredIngredient*>(inventory[i]);
            auto c = dynamic_cast<CursedIngredient*>(inventory[i]);
            auto p = dynamic_cast<Potion*>(inventory[i]);

            if (s) {
                cout << "Type : Sacred; Divine Level: " << s->getDivineLevel() << "\n";
            }else if (c) {
                cout << "Type : Cursed; Curse Level: " << c->getCurseLevel() << "\n";
            }else if (p) {
                cout << "Type : Potion; Test for effect!\n";
            }
        }
    }
}

Product* Shop::selectProduct(int idx) {
    return this->inventory[idx];
}

void Shop::itemDescription(int idx) {

    Product* prod = this->inventory[idx]->clone();

    if (dynamic_cast<SacredIngredient*>(prod) != nullptr) {
        cout << "Sacred Ingr\n";
    }else if (dynamic_cast<CursedIngredient*>(prod) != nullptr) {
        cout << "Cursed Ingr\n";
    }else if (dynamic_cast<Potion*>(prod)  != nullptr){
        cout << "Potion\n";
    }else cout << "This isn't a valid item\n";

    delete prod;
}

const vector<Product*>& Shop::getInventory() const {
    return this->inventory;
}

void Shop::removeProduct(Product* prod) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == prod) {
            delete inventory[i];
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}

void Shop::loadFromFile(const string& FILENAME) {
    ifstream fin(FILENAME);

    try {
        if (!fin.is_open())
            throw InvalidOptionException("File cannot be opened!");

        for (auto& item : inventory) {
            delete item;
        }

        inventory.clear();

        int n;

        fin >> n;
        fin.ignore();

        for (int i = 0; i < n; i++) {
            string type;
            getline(fin, type);

            if (type == "Sacred") {
                string name, essence;
                double price, divineLevel;
                int quality;

                getline(fin, name);
                fin >> price;
                fin.ignore();
                fin >> quality;
                fin.ignore();
                getline(fin, essence);
                fin >> divineLevel;
                fin.ignore();

                Product* prod = new SacredIngredient(name, price, quality, essence, divineLevel);

                inventory.push_back(prod);
            }else if (type == "Cursed") {
                string name, essence;
                double price, curseLevel;
                int quality;

                getline(fin, name);
                fin >> price;
                fin.ignore();
                fin >> quality;
                fin.ignore();
                getline(fin, essence);
                fin >> curseLevel;
                fin.ignore();

                Product* prod = new CursedIngredient(name, price, quality, curseLevel, essence);

                inventory.push_back(prod);
            }else if (type == "Potion") {
                string name, d_essence, c_essence;
                double price, divineLevel, curseLevel;
                int quality;

                getline(fin, name);
                fin >> price;
                fin.ignore();
                fin >> quality;
                fin.ignore();
                getline(fin, d_essence);
                fin >> divineLevel;
                fin.ignore();
                getline(fin, c_essence);
                fin >> curseLevel;
                fin.ignore();

                Product* prod = new Potion(name, price, quality, divineLevel, d_essence, curseLevel, c_essence);

                inventory.push_back(prod);
            }
        }

        fin.close();

        cout << "Shop inventory loaded from file\n";

    } catch (const InvalidOptionException& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}


void Shop::saveToFile() {
    ofstream fout(FILENAME);

    try {
        if (!fout.is_open())
            throw InvalidOptionException("Can't open file!");

        fout << inventory.size() << "\n";

        for (const auto& item : inventory) {
            if (dynamic_cast<SacredIngredient*>(item)) {
                auto s = dynamic_cast<SacredIngredient*>(item);

                fout << "Sacred\n";
                fout << s->getName() << "\n";
                fout << s->getPrice() << "\n";
                fout << s->getQuality() << "\n";
                fout << s->getEssence() << "\n";
                fout << s->getDivineLevel() << "\n";
            }else if (dynamic_cast<CursedIngredient*>(item)) {
                auto c = dynamic_cast<CursedIngredient*>(item);

                fout << "Cursed\n";
                fout << c->getName() << "\n";
                fout << c->getPrice() << "\n";
                fout << c->getQuality() << "\n";
                fout << c->getEssence() << "\n";
                fout << c->getCurseLevel() << "\n";
            }else if (dynamic_cast<Potion*>(item)) {
                auto p = dynamic_cast<Potion*>(item);
                auto s = dynamic_cast<SacredIngredient*>(p);
                auto c = dynamic_cast<CursedIngredient*>(p);

                fout << "Potion\n";
                fout << p->getName() << "\n";
                fout << p->getPrice() << "\n";
                fout << p->getQuality() << "\n";
                fout << s->getEssence() << "\n";
                fout << s->getDivineLevel() << "\n";
                fout << c->getEssence() << "\n";
                fout << c->getCurseLevel() << "\n";
            }
        }

        fout.close();

        cout << "Shop inventory saved to file\n";
    } catch (const InvalidOptionException& e) {
        cout << "ERROR\n" << e.what() << "\n";
    }

}