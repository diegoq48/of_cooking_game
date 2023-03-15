//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"
#include "Table.h"



class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;
        int leftCustomers = 0;
//        int startTime = ofTime.getAsSeconds();

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor;
        void initItems();
        void initCounters();
        void initDecoration();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        int leftClientGet();
        void leftClientSet();
};
