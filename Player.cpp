#include "Player.h"
#include "Potion.h"
#include "Shop.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOUSER
#define BYTE_DEFINED
#include <windows.h>

using namespace std;

const string FILENAME = "inventory_player.txt";

void delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void playExplosion() {
    const char* frames[] = {
        "      *      \n",

        "    * + *    \n",

        "  * + * + *  \n",

        "* + * + * + *\n",

        " + . + . + . \n",

        "  . . . . .  \n",

        "   .  .  .  \n",

        "      .       \n"
    };

    const char* culori[] = {
        "\033[31m",
        "\033[31m",
        "\033[31m",
        "\033[31m",
        "\033[31m",
        "\033[31m",
        "\033[31m",
        "\033[31m"
    };

    for (int i = 0; i < 8; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playFlameMyth() {
    const char* frames[] = {
        "        *        \n",
        "      * + *      \n",
        "    *+  +  +*    \n",
        "   + * (|) * +   \n",
        "  *+--( + )--+*  \n",
        "   + * (|) * +   \n",
        "    *+  +  +*    \n",
        "      * + *      \n",
        "        *        \n"
    };

    const char* culori[] = {
        "\033[35m",
        "\033[35m",
        "\033[95m",
        "\033[93m",
        "\033[93m",
        "\033[93m",
        "\033[35m",
        "\033[35m",
        "\033[35m"
    };

    for (int i = 0; i < 9; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playFlameEarth() {
    const char* frames[] = {
        "        ~        \n",
        "      ~ ) ~      \n",
        "    ~)  )  )~    \n",
        "   ) ~ (()) ~ )   \n",
        "  ~)--( ) )--()  \n",
        "   ) ~ (()) ~ )   \n",
        "    ~)  )  )~    \n",
        "      ~ ) ~      \n",
        "        ~        \n"
    };

    const char* culori[] = {
        "\033[32m",
        "\033[33m",
        "\033[32m",
        "\033[33m",
        "\033[32m",
        "\033[33m",
        "\033[32m",
        "\033[33m",
        "\033[32m"
    };

    for (int i = 0; i < 9; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playFlameHellish() {
    const char* frames[] = {
        "        !        \n",
        "      ! X !      \n",
        "    !X  X  X!    \n",
        "   X ! |||/ ! X   \n",
        "  !X--( X )--X!  \n",
        "   X ! /||| ! X   \n",
        "    !X  X  X!    \n",
        "      ! X !      \n",
        "        !        \n"
    };

    const char* culori[] = {
        "\033[91m",
        "\033[91m",
        "\033[93m",
        "\033[93m",
        "\033[30m",
        "\033[93m",
        "\033[93m",
        "\033[91m",
        "\033[91m"
    };

    for (int i = 0; i < 9; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playOceanMyth() {
    const char* frames[] = {
        "  ~  ~  ~  ~  ~  \n",
        " ~~~ ~~~ ~~~ ~~~  \n",
        "~~~~~~~~~~~~~~~~~~~~\n",
        " ~~*~~~*~~~*~~~*~~\n",
        "~~~~~~~~~~~~~~~~~~~~\n",
        " ~~~ ~~~ ~~~ ~~~  \n",
        "  ~  ~  ~  ~  ~  \n"
    };

    const char* culori[] = {
        "\033[34m",
        "\033[34m",
        "\033[94m",
        "\033[92m",
        "\033[94m",
        "\033[34m",
        "\033[34m"
    };

    for (int i = 0; i < 7; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playOceanEarth() {
    const char* frames[] = {
        "  _  _  _  _  _  \n",
        " ___ ___ ___ ___  \n",
        "____________________\n",
        " __~___~___~___~__\n",
        "____________________\n",
        " ___ ___ ___ ___  \n",
        "  _  _  _  _  _  \n"
    };

    const char* culori[] = {
        "\033[34m",
        "\033[34m",
        "\033[90m",
        "\033[30m",
        "\033[90m",
        "\033[34m",
        "\033[34m"
    };

    for (int i = 0; i < 7; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playOceanHellish() {
    const char* frames[] = {
        "  x  x  x  x  x  \n",
        " xxx xxx xxx xxx  \n",
        "xxxxxxxxxxxxxxxxxxxx\n",
        " xx*xxx*xxx*xxx*xx\n",
        "xxxxxxxxxxxxxxxxxxxx\n",
        " xxx xxx xxx xxx  \n",
        "  x  x  x  x  x  \n"
    };

    const char* culori[] = {
        "\033[31m",
        "\033[31m",
        "\033[35m",
        "\033[91m",
        "\033[35m",
        "\033[31m",
        "\033[31m"
    };

    for (int i = 0; i < 7; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playHolyMyth() {
    const char* frames[] = {
        "        |        \n",
        "       |||       \n",
        "      |||||      \n",
        "   * ||||||| *   \n",
        "  ** |||+||| **  \n",
        "   * ||||||| *   \n",
        "      |||||      \n",
        "       |||       \n",
        "        |        \n"
    };

    const char* culori[] = {
        "\033[97m",
        "\033[97m",
        "\033[93m",
        "\033[97m",
        "\033[93m",
        "\033[97m",
        "\033[93m",
        "\033[97m",
        "\033[97m"
    };

    for (int i = 0; i < 9; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playHolyEarth() {
    const char* frames[] = {
        "        |        \n",
        "       |||       \n",
        "      |||||      \n",
        "   . ||||||| .   \n",
        "  .. |||+||| ..  \n",
        "   . ||||||| .   \n",
        "      |||||      \n",
        "       |||       \n",
        "        |        \n"
    };

    const char* culori[] = {
        "\033[97m",
        "\033[97m",
        "\033[37m",
        "\033[90m",
        "\033[30m",
        "\033[90m",
        "\033[37m",
        "\033[97m",
        "\033[97m"
    };

    for (int i = 0; i < 9; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

void playHolyHellish() {
    const char* frames[] = {
        "        |        \n",
        "       |||       \n",
        "      |||||      \n",
        "   x ||||||| x   \n",
        "  xx |||+||| xx  \n",
        "   x ||||||| x   \n",
        "      |||||      \n",
        "       |||       \n",
        "        |        \n"
    };

    const char* culori[] = {
        "\033[95m",
        "\033[95m",
        "\033[35m",
        "\033[35m",
        "\033[33m",
        "\033[35m",
        "\033[35m",
        "\033[95m",
        "\033[95m"
    };

    for (int i = 0; i < 9; i++) {
        cout << "\033[1m" << culori[i]
                  << frames[i]
                  << "\033[0m";
        delay(120);
    }
}

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


void Player::buyProduct(Product* prod, Shop& shop) {
    
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

        shop.removeProduct(prod);
    }

}

void Player::displayInventory() {
    if (this->inventory.size() == 0) {
        cout << "EMPTY\n";
    }else {
        for (int i = 0; i < this->inventory.size(); i++) {
            cout << "Item " << i + 1 << " : " << inventory[i]->getName() << " , " << inventory[i]->calculatePrice() << " gold  ";
            cout << "Quality : " << this->inventory[i]->getQuality() << "  ";

            auto s = dynamic_cast<SacredIngredient*>(inventory[i]);
            auto c = dynamic_cast<CursedIngredient*>(inventory[i]);
            auto p = dynamic_cast<Potion*>(inventory[i]);

            if (p != nullptr) {
                cout << "Type : Potion; Test for effect!\n";
            }else if (s != nullptr) {
                cout << "Type : Sacred; Divine Level: " << s->getDivineLevel() << "\n";
            }else if (c != nullptr) {
                cout << "Type : Cursed; Curse Level: " << c->getCurseLevel() << "\n";
            }
        }
    }
}

Potion* Player::createPotion(Product* &prod1, Product* &prod2) {

    double sacred_score = 0, cursed_score = 0;
    int avgQuality = (prod1->getQuality() + prod2->getQuality()) / 2;
    int avgBasePrice = (prod1->calculatePrice() + prod2->calculatePrice()) / 2.0;
    string potion_name = "Potion of " + prod1->getName() + " and " + prod2->getName();
    string sacred_essence = "", cursed_essence = "", combined_essence;

    SacredIngredient* s1 = dynamic_cast<SacredIngredient*>(prod1);
    CursedIngredient* c1 = dynamic_cast<CursedIngredient*>(prod1);
    SacredIngredient* s2 = dynamic_cast<SacredIngredient*>(prod2);
    CursedIngredient* c2 = dynamic_cast<CursedIngredient*>(prod2);

    if (s1 != nullptr) {
        sacred_score += s1->addToPotion();
        sacred_essence = s1->getEssence();
    }else if (c1 != nullptr) {
        cursed_score += c1->addToPotion();
        cursed_essence = c1->getEssence();
    }

    if (s2 != nullptr) {
        sacred_score += s2->addToPotion();
        sacred_essence += s2->getEssence();
    }
    else if (c2 != nullptr) {
        cursed_score += c2->addToPotion();
        cursed_essence += c2->getEssence();
    }

    combined_essence = sacred_essence + cursed_essence;

    Potion* temp = new Potion(potion_name, avgBasePrice, avgQuality, sacred_score, combined_essence, cursed_score, combined_essence);

    delete prod1;
    delete prod2;

    prod1 = nullptr;
    prod2 = nullptr;

    this->clearInventory();

    return temp;
}

void Player::sellPotion(int idx, Shop& shop) {
    double initial_price = this->inventory[idx]->calculatePrice();

    cout << "The " << this->inventory[idx]->getName() << " has a value of " << initial_price << "\n";

    this->inventory[idx]->increasePrice();

    shop.addProduct(this->inventory[idx]);

    this->setBalance(this->inventory[idx]->calculatePrice());

    delete inventory[idx];

    inventory[idx] = nullptr;

    this->clearInventory();
}

void Player::testPotion(Product* potion) {
    auto s = dynamic_cast<Potion*>(potion);

    if (s != nullptr) {
        if (s->getStability() < 50) {
            cout << "You try prying the lid off of the container, but it won't budge. After minutes of effort, you triumph, but the concoction isn't stable and explodes in your hands!\n";

            delay(200);

            playExplosion();
        }else {
            string potion_essence = s->getEssence();

            if (potion_essence == "FlameMyth") {
                playFlameMyth();
            }else if (potion_essence == "FlameEarth") {
                playFlameEarth();
            }else if (potion_essence == "FlameHellish") {
                playFlameHellish();
            }else if (potion_essence == "OceanicMyth") {
                playOceanMyth();
            }else if (potion_essence == "OceanicEarth") {
                playOceanEarth();
            }else if (potion_essence == "OceanicHellish") {
                playOceanHellish();
            }else if (potion_essence == "HolyMyth") {
                playHolyMyth();
            }else if (potion_essence == "HolyEarth") {
                playHolyEarth();
            }else if (potion_essence == "HolyHellish") {
                playHolyHellish();
            }
        }
    }else {
        cout << "Not a potion!\n";
    }
}

Product*& Player::selectProduct(int idx) {
    return this->inventory[idx];
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

const vector<Product*>& Player::getInventory() const {
    return this->inventory;
}

void Player::loadFromFile() {
    ifstream fin(FILENAME);

    try {
        if (!fin.is_open())
            throw InvalidOptionException("File cannot be opened!");

        for (auto& item : inventory) {
            delete item;
        }

        inventory.clear();

        getline(fin, this->name);

        int n;
        double balance;

        fin >> balance;
        fin.ignore();
        this->balance = balance;
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

        cout << "Player inventory loaded from file\n";

    } catch (const InvalidOptionException& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}

void Player::saveToFile() {
    ofstream fout(FILENAME);

    try {
        if (!fout.is_open())
            throw InvalidOptionException("Can't open file!");

        fout << getName() << '\n';

        fout << getBalance() << '\n';

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

        cout << "Player inventory saved to file\n";
    } catch (const InvalidOptionException& e) {
        cout << "ERROR\n" << e.what() << "\n";
    }
}

istream& operator>>(istream& is, Player& player) {
    cout << "Name: ";
    is >> player.name;

    cout << "\nBalance: ";
    is >> player.balance;

    return is;
}

ostream& operator<<(ostream& os, const Player& player) {
    os << "Name: " << player.name << "\n";
    os << "Balance: " << player.balance << "\n";

    return os;
}