#include "Product.h"
#include <string>
#include <iostream>

using namespace std;

Product::Product() {
    name = "N/A";
    price = 0;
    quality = 0;
}

Product::Product(string name, double price, int quality) {
    this->name = name;
    this->price = price;
    this->quality = quality;
}

Product::Product(const Product& prod) {
    name = prod.name;
    price = prod.price;
    quality = prod.quality;
}

Product& Product::operator=(const Product& prod) {
    if (this == &prod)
        return *this;

    name = prod.name;
    price = prod.price;
    quality = prod.quality;

    return *this;
}

double Product::calculatePrice() const {
    return 0;
}

ostream& operator<<(ostream& os, const Product& prod) {
    os << "Product : " << prod.name << " has a price of " << prod.price << " and a quality of " << prod.quality << ".\n";

    return os;
}

const string Product::getName() const{
    return this->name;
}