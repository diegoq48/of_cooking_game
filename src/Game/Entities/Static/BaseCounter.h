//
// Created by joshu on 11/3/2020.
//

#pragma once

// #include "Item.h"
#include "Entity.h"
#include "Ingredient.h"

class BaseCounter: public Entity {
    protected:
        Ingredient *item;
        int costOfIngredient;
    public:
        bool canGrab = true;
        BaseCounter(int x, int y, int width, int height, Ingredient* item, ofImage sprite, int costOfIngredient);
        Ingredient* getItem();
        virtual void showItem();
        bool getCanGrab() {
            return canGrab;
        }
        void setCanGrab(bool canGrab) {
            this->canGrab = canGrab;
        }
        int getCostOfIngredient(){
            return costOfIngredient;
        }

};
