//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}

// The function should should not care by the order of the ingredients except for the buns at the start and end
bool Burger::equals(Burger *burger) {
// check if the first element in ingredients is a bun
    if (ingredients[0]->name != "bottomBun"){
        return false;
    }
    if (ingredients[ingredients.size()-1]->name != "topBun"){
        return false;
    }
// check if all the ingredients in the burger are in the other burger
    for (Item* ingredient:ingredients){
        bool found = false;
        for (Item* otherIngredient:burger->ingredients){
            if (ingredient->name == otherIngredient->name){
                found = true;
                break;
            }
        }
        if (!found){
            return false;
        }
    }
    return true;
}