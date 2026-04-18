#pragma once

#include "Product.h"
#include <string>

using namespace std;

class CursedIngredient: virtual public Product {
protected:
    double curseLevel;
    string curseType;
public:
    CursedIngredient();
    CursedIngredient(string name, double price, int quality, double curseLevel, string curseType);
    CursedIngredient(const CursedIngredient& obj);
    CursedIngredient& operator=(const CursedIngredient& obj);
    virtual ~CursedIngredient();

    double addToPotion() override;
    double calculatePrice() const override;

};