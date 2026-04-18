#pragma once

#include "Product.h"
#include <string>

using namespace std;

class CursedIngredient: virtual public Product {
private:
    double rarity;
    string curseType;
public:
    CursedIngredient();
    CursedIngredient(string name, double price, int quality, double rarity, string curseType);
    CursedIngredient(const CursedIngredient& obj);
    CursedIngredient& operator=(const CursedIngredient& obj);
    virtual ~CursedIngredient();

    double addToPotion() override;
    double calculatePrice() const override;

};