#include "CursedIngredient.h"
#include "Exceptions.h"
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

const double CursedIngredient::getCurseLevel() const {
    return curseLevel;
}

istream& operator>>(istream &is, CursedIngredient& obj) {
    is >> static_cast<Product&>(obj);

    cout << "Essence: ";
    getline(is, obj.curseType);

    if (obj.curseType.empty())
        throw InvalidOptionException("Not a valid essence!");

    cout << "\nDivine level: ";
    is >> obj.curseLevel;

    if (obj.curseLevel < 0 || obj.curseLevel > 100)
        throw InvalidOptionException("Divine level must be between 0 and 100!");

    return is;
}

ostream& operator<<(ostream &os, const CursedIngredient& obj) {
    os << static_cast<const Product&>(obj);

    os << "Essence : " << obj.curseType << "\n";

    return os;
}
