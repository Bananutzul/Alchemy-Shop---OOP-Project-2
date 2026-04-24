#include "SacredIngredient.h"
#include <iostream>
#include <string>

#include "Exceptions.h"

using namespace std;

SacredIngredient::SacredIngredient() : Product() {};

SacredIngredient::SacredIngredient(string name, double price, int quality,
string essence, double divineLevel) : Product(name, price, quality) {
    this->essence = essence;
    this->divineLevel = divineLevel;
};

SacredIngredient::SacredIngredient(const SacredIngredient& obj) : Product(obj.name, obj.price, obj.quality) {
    divineLevel = obj.divineLevel;
    essence = obj.essence;
};

SacredIngredient& SacredIngredient::operator=(const SacredIngredient& obj) {
    if (this == &obj)
        return *this;

    Product::operator=(obj);

    divineLevel = obj.divineLevel;
    essence = obj.essence;

    return *this;
};

SacredIngredient::~SacredIngredient() {};

double SacredIngredient::addToPotion() {
    return divineLevel * (quality / 10.0);
}

double SacredIngredient::calculatePrice() const {
    return price + (0.2 * quality + 0.8 * divineLevel);
}

Product* SacredIngredient::clone() const {
    return new SacredIngredient(*this);
}

const string SacredIngredient::getEssence() const {
    return essence;
}

const double SacredIngredient::getDivineLevel() const {
    return divineLevel;
}

istream& operator>>(istream &is, SacredIngredient& obj) {
    is >> static_cast<Product&>(obj);

    cout << "Essence: ";
    getline(is, obj.essence);

    if (obj.essence.empty())
        throw InvalidOptionException("Not a valid essence!");

    cout << "\nDivine level: ";
    is >> obj.divineLevel;

    if (obj.divineLevel < 0 || obj.divineLevel > 100)
        throw InvalidOptionException("Divine level must be between 0 and 100!");

    return is;
}

ostream& operator<<(ostream &os, const SacredIngredient& obj) {
    os << static_cast<const Product&>(obj);

    os << "Essence : " << obj.essence << "\n";

    return os;
}