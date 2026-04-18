#pragma once

#include "SacredIngredient.h"
#include "CursedIngredient.h"
#include <string>
#include <vector>

using namespace std;

class Potion: public SacredIngredient, public CursedIngredient {
private:
    double stability; // 0 - 100
    string potionName;
public:
    Potion();
    Potion(string name, double price, int quality, 
    double divineLevel, string essence, double curseLevel, string curseType,
    string potionName);
    Potion(const Potion& obj);
    Potion& operator=(const Potion& obj);
    virtual ~Potion();

    double addToPotion() override;
    double calculatePrice() const override;
    void calculateStability();
    void namePotion();
    virtual Product* clone() const override;

    void setStability(double temp);
    void setName(string temp);
};