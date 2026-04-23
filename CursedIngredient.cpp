#include "CursedIngredient.h"
#include <string>
#include <iostream>

using namespace std;

CursedIngredient::CursedIngredient() : Product() {};

CursedIngredient::CursedIngredient(string name, double price, int quality,
double curseLevel, string curseType) : Product(name, price, quality) {
    this->curseLevel = curseLevel;
    this->curseType = curseType;
}

CursedIngredient::CursedIngredient(const CursedIngredient& obj) : Product(obj.name, obj.price, obj.quality) {
    curseLevel = obj.curseLevel;
    curseType = obj.curseType;
}

CursedIngredient& CursedIngredient::operator=(const CursedIngredient& obj) {
    if (this == &obj)
        return *this;

    Product::operator=(obj);

    curseLevel = obj.curseLevel;
    curseType = obj.curseType;

    return *this;
}

CursedIngredient::~CursedIngredient() {};

double CursedIngredient::addToPotion() {
    return curseLevel * (quality / 10.0);
}

double CursedIngredient::calculatePrice() const {
    return price + (0.2 * quality + 0.8 * curseLevel);
}

Product* CursedIngredient::clone() const {
    return new CursedIngredient(*this);
}

const string CursedIngredient::getEssence() const {
    return curseType;
}
