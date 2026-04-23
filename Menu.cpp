#include "Menu.h"
#include <iostream>
#include <limits>
#include "Exceptions.h"

using namespace std;

void waitForEnter() {
    cout << "Press Enter to continue\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

Menu::Menu(Player player, Shop shop) {
    this->player = player;
    this->shop = shop;
}

void Menu::startMenu() {
    bool running = true;

    while (running) {

        clearScreen();

        cout << "                                       ----Welcome to----\n";
        cout << R"(______________ ______________    _____  .____   _________   ___ ______________   _____ _____.___.
\__    ___/   |   \_   _____/   /  _  \ |    |  \_   ___ \ /   |   \_   _____/  /     \\__  |   |
  |    | /    ~    \    __)_   /  /_\  \|    |  /    \  \//    ~    \    __)_  /  \ /  \/   |   |
  |    | \    Y    /        \ /    |    \    |__\     \___\    Y    /        \/    Y    \____   |
  |____|  \___|_  /_______  / \____|__  /_______ \______  /\___|_  /_______  /\____|__  / ______|
                \/        \/          \/        \/      \/       \/        \/         \/\/
                       ____________________________ _____________________
                      /   _____/\__    ___/\_____  \\______   \_   _____/
     ______   ______  \_____  \   |    |    /   |   \|       _/|    __)_   ______   ______
    /_____/  /_____/  /        \  |    |   /    |    \    |   \|        \ /_____/  /_____/
                     /_______  /  |____|   \_______  /____|_  /_______  /
                             \/                    \/       \/        \/                          )";

        cout << endl;

        shop.displayInventory();

        cout << "\nCurrent balance : " << player.getBalance() << '\n' << '\n';

        cout << "---Choose an option---\n";
        cout << "1.Buy a product\n";
        cout << "2.Check your inventory\n";
        cout << "3.Create a potion\n";
        cout << "4.Test a potion\n";
        cout << "5.Sell a potion\n";
        cout << "6.Restock (costs 200)\n";
        cout << "0.Exit\n";

        try {
            int option;

            if (!(cin >> option)) {
                cin.clear();

                while (cin.get() != '\n')
                    continue;

                throw InvalidOptionException("Invalid Option!\n");
            }else {
                switch (option) {
                    case 1:
                        clearScreen();

                        shop.displayInventory();

                        try {
                            if (shop.getInventory().size() == 0)
                                throw InvalidOptionException("Shop is empty!\n");
                        } catch (const InvalidOptionException& e) {
                            cout << "ERROR : " << e.what() << endl;
                        }

                        cout << "\nChoose an item to purchase!\n";

                        try {
                            int temp;

                            if (!(cin >> temp)) {
                                cin.clear();

                                while (cin.get() != '\n')
                                    continue;

                                throw InvalidOptionException("Invalid Option!\n");
                            }else {
                                temp--;

                                if (temp < 0 || temp >= shop.getInventory().size()) {
                                    throw InvalidOptionException("Index Out of Range!\n");
                                }else {
                                    player.buyProduct(shop.selectProduct(temp), shop);
                                    cout << "You successfully bought the product!\n";
                                    player.saveToFile();
                                    shop.saveToFile();
                                }
                            }
                        } catch (const InvalidOptionException& e) {
                            cout << "\nERROR: " << e.what() << '\n';
                        }

                        waitForEnter();
                        break;
                    case 2:
                        clearScreen();
                        cout << "---Your Inventory---\n";
                        player.displayInventory();
                        waitForEnter();
                        break;
                    case 3:
                        clearScreen();

                        cout << "Choose two ingredients to combine!\n";

                        try {
                            if (player.getInventory().size() == 0 || player.getInventory().size() == 1)
                                throw InvalidOptionException("You don't have any items!\n");

                            cout << "---Your Inventory---\n";
                            player.displayInventory();

                            int temp1, temp2;

                            if (!(cin >> temp1)) {
                                cin.clear();

                                while (cin.get() != '\n')
                                    continue;

                                throw InvalidOptionException("Invalid Option!\n");
                            }else {
                                temp1--;

                                if (temp1 < 0 || temp1 >= player.getInventory().size())
                                    throw InvalidOptionException("Index Out of Range!\n");
                            }
                            cout << "Enter a second item!\n";

                            if (!(cin >> temp2)) {
                                cin.clear();

                                while (cin.get() != '\n')
                                    continue;

                                throw InvalidOptionException("Invalid Option!\n");
                            }else {
                                temp2--;

                                if (temp2 < 0 || temp2 >= player.getInventory().size())
                                    throw InvalidOptionException("Index Out of Range!\n");
                                else if (temp1 == temp2)
                                    throw InvalidOptionException("You can't combine an item with itself!\n");
                            }

                            auto s1 = dynamic_cast<SacredIngredient*>(player.selectProduct(temp1));
                            auto s2 = dynamic_cast<SacredIngredient*>(player.selectProduct(temp2));
                            auto c1 = dynamic_cast<CursedIngredient*>(player.selectProduct(temp1));
                            auto c2 = dynamic_cast<CursedIngredient*>(player.selectProduct(temp2));
                            auto p1 = dynamic_cast<Potion*>(player.selectProduct(temp1));
                            auto p2 = dynamic_cast<Potion*>(player.selectProduct(temp2));

                            if (p1 != nullptr || p2 != nullptr)
                                throw InvalidOptionException("You can't use a potion to create another potion!");

                            if ((s1 != nullptr || c1 != nullptr) && (s2 != nullptr || c2 != nullptr)) {
                                Potion* potion = player.createPotion(player.selectProduct(temp1), player.selectProduct(temp2));

                                double potion_price = potion->calculatePrice();

                                player.setBalance(potion_price);

                                player.buyProduct(potion, shop);

                                cout << "You have successfully created a potion!\n";
                                player.saveToFile();
                            }else throw InvalidOptionException("You haven't selected valid ingredients!\n");

                        } catch (const InvalidOptionException& e) {
                            cout << "\nERROR: " << e.what() << '\n';
                        }

                        waitForEnter();
                        break;
                    case 4:
                        clearScreen();

                        try {
                            cout << "---Your Inventory---\n";
                            player.displayInventory();

                            if (player.getInventory().size() == 0)
                                throw InvalidOptionException("You don't have any items!\n");
                            else {
                                cout << "Choose a potion to test!(Must be a potion)\n";

                                int temp;

                                if (!(cin >> temp)) {
                                    cin.clear();

                                    while (cin.get() != '\n')
                                        continue;

                                    throw InvalidOptionException("Invalid Option!\n");
                                }else {
                                    temp--;

                                    if (temp < 0 || temp >= player.getInventory().size())
                                        throw InvalidOptionException("Index Out of Range!\n");

                                    else if (dynamic_cast<Potion*>(player.selectProduct(temp)) == nullptr)
                                        throw InvalidOptionException("\nYou can't test something that's not a potion!!\n");

                                    player.testPotion(player.selectProduct(temp));
                                }
                            }
                        } catch (const InvalidOptionException& e) {
                            cout << "\nERROR: " << e.what() << '\n';
                        }

                        waitForEnter();
                        break;
                    case 5:
                        clearScreen();

                        try {
                            cout << "---Your Inventory---\n";
                            player.displayInventory();

                            if (player.getInventory().size() == 0)
                                throw InvalidOptionException("You don't have any items!\n");
                            else {
                                cout << "Choose a potion to sell!(Must be a potion)\n";

                                int temp;

                                if (!(cin >> temp)) {
                                    cin.clear();

                                    while (cin.get() != '\n')
                                        continue;

                                    throw InvalidOptionException("Invalid Option!\n");
                                }else {
                                    temp--;

                                    if (temp < 0 || temp >= player.getInventory().size())
                                        throw InvalidOptionException("Index Out of Range!\n");

                                    else if (dynamic_cast<Potion*>(player.selectProduct(temp)) == nullptr)
                                        throw InvalidOptionException("\nYou can't test something that's not a potion!!\n");

                                    player.sellPotion(temp, shop);
                                    player.saveToFile();
                                    shop.saveToFile();
                                }
                            }
                        } catch (const InvalidOptionException& e) {
                            cout << "\nERROR: " << e.what() << '\n';
                        }

                        waitForEnter();
                        break;
                    case 6:
                        clearScreen();

                        try {
                            if (shop.getInventory().size() != 0)
                                throw InvalidOptionException("Can't restock the shop while it's not empty!\n");

                            if (player.getBalance() < 200)
                                throw InvalidOptionException("You have not enough money to restock!\n");

                            player.setBalance(-200);

                            shop.loadFromFile("inventory_shop_initial.txt");
                            shop.saveToFile();
                        } catch (const InvalidOptionException& e) {
                            cout << "ERROR: " << e.what() << '\n';
                        }

                        waitForEnter();
                        break;
                    case 0:
                        cout << "Goodbye!\n";
                        running = false;
                        break;
                    default:
                        cout << "Not a valid option!\n";
                }
            }
        } catch (const InvalidOptionException& e) {
            cout << "\nERROR: " << e.what() << '\n';
        }
    }
}