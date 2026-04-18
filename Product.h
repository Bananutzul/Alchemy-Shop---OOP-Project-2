#pragma once

#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;
    int quality; // will be used to calculate effectiveness of potion and price, from 0 - 10

public:
    Product();
    Product(string name, double price, int quality);
    Product(const Product& prod);
    Product& operator=(const Product& prod);
    virtual ~Product();

    virtual double addToPotion() = 0;
    virtual double calculatePrice() const;
    virtual Product* clone() const = 0;

    friend ostream& operator<<(ostream &os, const Product& prod);
};