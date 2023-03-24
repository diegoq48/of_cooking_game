

#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initDecoration();
    initClients();
    generateClient();

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Ingredient(cheeseImg, "cheese",3 );
    lettuce = new Ingredient(lettuceImg, "lettuce", 2);
    tomato = new Ingredient(tomatoImg, "tomato", 2);
    burger = new Ingredient(burgerImg, "patty", 4);
    botBread = new Ingredient(botBreadImg, "bottomBun", 1);
    topBread = new Ingredient(topBreadImg, "topBun", 1);

}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg, 800));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));
}
void Restaurant::initDecoration(){
    ofImage DecorationSheet, tableImg, seatImg;
    DecorationSheet.load("images/sprite.png");
    tableImg.cropFrom(DecorationSheet, 0, 0, 100, 100);
    seatImg.cropFrom(DecorationSheet, 107, 13, 34, 37);
    Table *table1 = new Table(130, 40, 96, 117, 5, seatImg,tableImg);
    Table *table2 = new Table(380, 40, 96, 117, 4, seatImg,tableImg);
    Table *table3 = new Table(600, 40, 96, 117, 3, seatImg,tableImg);
    Table *table4 = new Table(130, 200, 96, 117, 6, seatImg,tableImg);
    Table *table5 = new Table(380, 200, 96, 117, 2, seatImg,tableImg);
    entityManager->addEntity(table1);
    entityManager->addEntity(table2);
    entityManager->addEntity(table3);
    entityManager->addEntity(table4);
    entityManager->addEntity(table5);
}

void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
    }
    player->tick();
    entityManager->tick();
    if(entityManager->leftClients >= 10){
        std::cout << "Lost" << entityManager->leftClients << std::endl;
        lost = true;
    }
    if(entityManager->servedClients >= 10){
        std::cout << "Won" << entityManager->servedClients << std::endl;
        won = true;
    }

}

void Restaurant::setMoney(int money) {
    this->money = money;
}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    // add random ingredients to burger
    Ingredient* ingredients[4] = {cheese, lettuce, tomato, burger};
    for (int i = 0; i < rand()%10 ; i++){
        b->addIngredient(ingredients[rand()%3]);
    }
    b->addIngredient(topBread);
    if (this->ticks % 2000 == 0){
        entityManager->addClient(new inspector(0, 50, 64, 72,ofImage("images/People/darthVader.png"), b));
        return;
    }
    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b));
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofDrawBitmapString("Lives: " + to_string(10-entityManager->leftClients), ofGetWidth()/2, 30);
    ofDrawBitmapString("Served Clients: " + to_string(entityManager->servedClients) + "/10", ofGetWidth()/2, 50);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient(){
    //Check if the player has a burger with empty ingredients
    if(player->getBurger()->getIngredients().size() == 0 || entityManager->firstClient == nullptr){
        return;
    }

    if (player->getBurger()->equals(entityManager->firstClient->getBurger()) ){
        money += entityManager->firstClient->serve(player->getBurger());
        player->getBurger()->clear();
    } 
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    switch(key){
        case 's':
            serveClient();
            player->getBurger()->clear();
            break;
    }
}

void Restaurant::reset(){
    std::cout << "Reset" << std::endl;
    entityManager->reset();
    std::cout << entityManager->leftClients << std::endl;
    entityManager->leftClients = 0;
    money = 0;
    lost = false;
    ticks = 0;
    initCounters();
    initDecoration();
    initClients();
    ///player->reset();
}
