#pragma once

#include "SacredIngredient.h"
#include "CursedIngredient.h"
#include <string>
#include <vector>

using namespace std;

class Potion: public SacredIngredient, public CursedIngredient {
private:
    int stability; // 0 - 100
    string potionName;
public:
    Potion(string name, double price, int quality, double divineLevel, string essence, double curseLevel, string curseType,
    int stability, string potionName);
    Potion(const Potion& obj);
    Potion& operator=(const Potion& obj);
    virtual ~Potion();

    void addToPotion() override;
    double calculatePrice() const override;
    int calculateStability();
    void namePotion();

};