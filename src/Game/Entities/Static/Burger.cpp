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

void Burger::addIngredient(Ingredient *item) {
    ingredients.push_back(item);
}

void Burger::removeIngredient() {
    if(!ingredients.empty()){
    ingredients.pop_back();
    }
}
void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.clear();
}
int Burger::getCost(){
    int cost = 0;
    for (Ingredient* ingredient:ingredients){
        cost += ingredient->getCost();
    }
    return cost;
}

// The function  should not care by the order of the ingredients except for the buns at the start and end
bool Burger::equals(Burger *burger) {
    // Check if the first element in ingredients is a bottom bun
    if (ingredients[0]->name != "bottomBun") {
        return false;
    }
    if (ingredients[ingredients.size() - 1]->name != "topBun") {
        return false;
    }

    // Count ingredients in the first burger, excluding buns
    std::map<std::string, int> count1;
    for (size_t i = 1; i < ingredients.size() - 1; i++) {
        count1[ingredients[i]->name]++;
    }

    // Count ingredients in the second burger, excluding buns
    std::map<std::string, int> count2;
    for (size_t i = 1; i < burger->ingredients.size() - 1; i++) {
        count2[burger->ingredients[i]->name]++;
    }

    // Compare the counts of ingredients in both burgers
    return count1 == count2;
}