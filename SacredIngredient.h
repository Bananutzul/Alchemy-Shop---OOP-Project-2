#pragma once

#include "Product.h"
#include <string>

using namespace std;

class SacredIngredient: virtual public Product {
private:
    double divineLevel; // will affect ingredient effectiveness, 0 - 100
    string essence; // determines the effect

public:
    SacredIngredient();
    SacredIngredient(string name, double price, int quality, string essence, double divineLevel);
    SacredIngredient(const SacredIngredient& obj);
    SacredIngredient& operator=(const SacredIngredient& obj);

    virtual ~SacredIngredient();

    double addToPotion() override;
    double calculatePrice() const override;
};
