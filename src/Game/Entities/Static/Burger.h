//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"
# include "Ingredient.h"

class Burger {
  private:
    int x, y, width, height;
    vector<Ingredient*> ingredients;
  public:
    Burger(int, int, int, int);
    void addIngredient(Ingredient *item);
    void render();
    void clear();
    void setY(int y) {
        this->y = y;
    }
    bool equals(Burger *burger);  
    void removeIngredient();
    vector<Ingredient *> getIngredients() {
        return ingredients;
    }
    int getCost();
};