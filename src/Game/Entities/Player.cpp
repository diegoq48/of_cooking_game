#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    this->priviousCounter = nullptr;
    this->ingredientsToCook.push_back("patty");
}

void Player::tick(){
    chefAnim->tick();
    BaseCounter *ac = getActiveCounter();
    // In this update function we want to check if the activecounter have getCanGrab() == false so that when
    //the players activate is cooking of the counter it will start a progress bar tht will be a method in the counter
    // class
    // All counters that getCanGrab() == false are the ones that are cooking

    if (ac != nullptr) {
            if(!ac->getCanGrab() ){
                ac->tick();
                }
        if (priviousCounter != ac) {
            speed = 0;
            priviousCounter = ac;
        }
    }
    else {
        priviousCounter = nullptr;
    }
    if(facing == "left"){
        x-=speed;
    }else if(facing == "right"){
        x+=speed;
    }
    if(x <= 0){
        facing = "right";
    }else if(x + width >= ofGetWidth()){
        facing = "left";
    }
    
}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    switch(key){
        case 'e':
            BaseCounter* ac = getActiveCounter();
            if(ac != nullptr){
                std::cout <<ac->getCanGrab() << "Stove?" << std::endl;   
                // If the counter is not cooking then we want to set the is cooking to true so that the counter start 
                if(!ac->getCanGrab()){
                    if (StoveCounter* sc = dynamic_cast<StoveCounter*>(ac)) {
                    std::cout << "cannot be grabbed and is Stove" << std::endl;
                        sc->setIsCooking(true);
                    }
                }
                // If the counter can be grabbed then we want to add the ingredient to the burger
                else {
                    Ingredient* item = ac->getItem();
                    if(item != nullptr){
                        burger->addIngredient(item);

                        // If the counter is a stove counter then we want to set the can grab to false because the player
                        // has already grabbed the cooked ingredient from the counter.
                        if (StoveCounter* sc = dynamic_cast<StoveCounter*>(ac)) {
                            sc->setCanGrab(false);
                        }
                    }
                }
            }
            break;
    }
    if(key == OF_KEY_LEFT){
        speed = 50;
        facing = "left"; 
        return;
    }
    if(key == OF_KEY_RIGHT){
        speed = 50;
        facing = "right";
        return;
    }
    if (key == OF_KEY_UP) {
        if (speed == 0){
            speed = 50;
            return;
        }
        speed = 0;
    }
    if(key == 'u'){
        burger->removeIngredient();
    }
}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }