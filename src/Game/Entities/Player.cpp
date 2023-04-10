#include "Player.h"
// constructor
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

// checks if the player has lost or won and if so changes the state to the win or loose state
// also checks for the counter that the player is on  also verifies if player is at the edge of the screen and changes the direction to the opposite direction 
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

//Equivilent to the draw function in ofApp
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
        // adds the ingredient of the counter to the burger 
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
                            this->money = this->money - 1;
                            burger->addIngredient(item);
                            if (StoveCounter* sc = dynamic_cast<StoveCounter*>(ac)) {
                                sc->setCanGrab(false);
                        }
                    }
                }
            }
            break;
        //changes the direction of the player to the left
        case(OF_KEY_LEFT):
            facing = "left";
            speed = 50;
            break;
        //changes the direction of the player to the right
        case(OF_KEY_RIGHT):
            facing = "right";
            speed = 50;
            break;
        // removes the last ingredient from the burger
        case('u'):
            burger->removeIngredient();
            break;
        default:
            break;
    }
}
// checks if the player is on a counter and returns the counter
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