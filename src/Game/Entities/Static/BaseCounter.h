//
// Created by joshu on 11/3/2020.
//

#pragma once

// #include "Item.h"
#include "Entity.h"
#include "Ingredient.h"

class BaseCounter: public Entity {
    private:
        Ingredient *item;

    public:
        BaseCounter(int x, int y, int width, int height, Ingredient* item, ofImage sprite);
        Ingredient* getItem();
        void showItem();
        bool getCanGrab() {
            return canGrab;
        }

};
