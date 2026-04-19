#include "Potion.h"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

Potion::Potion() : Product(), SacredIngredient(), CursedIngredient() {
    calculateStability();
};

Potion::Potion(string name, double price, int quality,
double divineLevel, string essence, double curseLevel, string curseType) : Product(name, price, quality), SacredIngredient(name, price, quality, essence, divineLevel), CursedIngredient(name, price, quality, curseLevel, curseType) {
    calculateStability();
};

Potion::Potion(const Potion& obj) : Product(obj), SacredIngredient(obj), CursedIngredient(obj) {
    stability = obj.stability;
};

Potion& Potion::operator=(const Potion& obj) {
    if (this == &obj)
        return *this;

    
    SacredIngredient::operator=(obj);
    CursedIngredient::operator=(obj);

    stability = obj.stability;

    return *this;
}

Potion::~Potion() {};

double Potion::addToPotion() {
    double sacredScore = SacredIngredient::addToPotion();
    double cursedScore = CursedIngredient::addToPotion();

    return (sacredScore - cursedScore) * (stability / 100.0);
}

void Potion::setStability(double temp){
    stability = temp;
}

void Potion::calculateStability() {
    double temp_stability = 100 - abs(divineLevel - curseLevel);

    setStability(temp_stability);
}

double Potion::calculatePrice() const {
    double sacredPrice = SacredIngredient::calculatePrice();
    double cursedPrice = CursedIngredient::calculatePrice();

    double finalPrice = 100 + (sacredPrice + cursedPrice) * (stability / 100.0);

    return finalPrice;
}

void Potion::setName(string temp) {
    name = temp;
}

Product* Potion::clone() const {
    return new Potion(*this);
}