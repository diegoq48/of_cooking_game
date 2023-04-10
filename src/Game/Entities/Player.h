#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"

class Player: public Entity{

    private:
        int speed = 5;
        int money = 30; 
        string facing = "right";
        Animation *chefAnim;
        Burger *burger;
        EntityManager* entityManager;
        BaseCounter* priviousCounter = nullptr;
        int ticks = 0;
        vector<string> ingredientsToCook;
        vector<StoveCounter*> stoves;
    public:
        Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void mousePressed(int, int, int);
        void setFacing(string);
        void clearBurger();
        BaseCounter* getActiveCounter();
        void reset();
        Burger* getBurger(){ return burger;
        }
        int getMoney(){ return money; }
        void setMoney(int newMoney){ money = newMoney; }
};