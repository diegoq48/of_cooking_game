// inheret from the item class
//
#include "Item.h"
#ifndef INGREDIENT_H
#define INGREDIENT_H

class Ingredient: public Item{
    private:
        int cost;
    public:
        Ingredient(ofImage sprite, string name, int cost): Item(sprite, name){
            this->cost = cost;
        }
        int getCost(){
            return cost;
        }
};
#endif