#include "SacredIngredient.h"
#include <iostream>
#include <string>

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

double SacredIngredient::addToPotion() {
    return divineLevel * (quality / 10);
}

double SacredIngredient::calculatePrice() const {
    return price * (0.2 * quality + 0.8 * divineLevel);
}