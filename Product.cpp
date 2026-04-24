#include "Product.h"
#include "Exceptions.h"
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

Product::~Product() {};

double Product::calculatePrice() const {
    return 0;
}

const string Product::getName() const{
    return this->name;
}

const int Product::getQuality() const {
    return quality;
}

const double Product::getPrice() const {
    return price;
}

void Product::increasePrice() {
    price *= 1.15;
}

void Product::setName(const string& name) {
    this->name = name;
}

istream& operator>>(istream &is, Product& prod) {
    cout << "Name: ";
    getline(is, prod.name);

    if (prod.name.empty())
        throw InvalidOptionException("Invalid name!");


    cout << "Base Price: ";

    double base_price;

    is >> base_price;

    is.ignore();

    if (base_price < 0)
        throw InvalidOptionException("Invalid base price!");

    prod.price = base_price;

    return is;
}

ostream& operator<<(ostream& os, const Product& prod) {
    os << "Product : " << prod.name << " has a price of " << prod.price << " and a quality of " << prod.quality << ".\n";

    return os;
}