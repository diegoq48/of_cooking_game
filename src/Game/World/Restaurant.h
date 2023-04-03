//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "ofMain.h"
#include "Table.h"
#include "Ingredient.h"
#include "Player.h"


class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int seconds = 0;
        int inspectorsSubstracted = 0;
        
//        int startTime = ofTime.getAsSeconds();

    public:
        int money =30;
        int leftCustomers = 0;
        bool won = false;
        Restaurant();
        bool lost = false;
        Player* getPlayer();
        void setPlayer(Player *player);
        Ingredient* cheese;
        Ingredient* lettuce;
        Ingredient* tomato;
        Ingredient* burger;
        Ingredient* botBread;
        Ingredient* topBread;
        ofImage floor;
        void initItems();
        void initCounters();
        void initDecoration();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        int getMoney();
        void keyPressed(int key);
        void setMoney(int newMoney);
        void reset();
};
