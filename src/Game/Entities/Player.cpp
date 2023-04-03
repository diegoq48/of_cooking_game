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
    // iterate thout the entitymanager entities and check if the entity is a stoveCounter
    // if it is a stoveCounter then add the ingredients to the vector
    // for (int i = 0; i < entityManager->entities.size(); i++) {
    //     if (StoveCounter* sc = dynamic_cast<StoveCounter*>(entityManager->entities[i])) {

    //     }
    // }
}

void Player::tick(){
    chefAnim->tick();
    BaseCounter *ac = getActiveCounter();


    for (int i = 0; i < entityManager->entities.size(); i++) {
    if (StoveCounter* sc = dynamic_cast<StoveCounter*>(entityManager->entities[i])) {
            sc->tick();
        }
        }
    
    

    if (ac != nullptr) {
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
    for (int i = 0; i < entityManager->entities.size(); i++) {
    if (StoveCounter* sc = dynamic_cast<StoveCounter*>(entityManager->entities[i])) {
            sc->showItem();
        }
        }
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        // if counter is a stove then execute the showitem of that class
        if (StoveCounter* sc = dynamic_cast<StoveCounter*>(ac)) {
            sc->showItem();
        }
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
    BaseCounter* ac = getActiveCounter();
    switch(key){
        case 'e':
                if(ac->getItem() == nullptr){return;}
                if(ac != nullptr && ac->getItem()->getCost() <= this->money){
                    if(!ac->getCanGrab()){
                        if (StoveCounter* sc = dynamic_cast<StoveCounter*>(ac)) {
                            std::cout << "cannot be grabbed and is Stove" << std::endl;
                            sc->setIsCooking(true);
                        }
                    }
                    else {
                        Ingredient* item = ac->getItem();
                        if(item != nullptr){
                            this->money = this->money - ac->getItem()->getCost();
                            burger->addIngredient(item);
                            if (StoveCounter* sc = dynamic_cast<StoveCounter*>(ac)) {
                                sc->setCanGrab(false);
                        }
                    }
                }
            }
            break;
        case(OF_KEY_LEFT):
            facing = "left";
            speed = 50;
            break;
        case(OF_KEY_RIGHT):
            facing = "right";
            speed = 50;
            break;
        case('u'):
            burger->removeIngredient();
            break;
        default:
            break;
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
void Player::reset(){
    this->burger->clear();
    money = 30;
}
void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }