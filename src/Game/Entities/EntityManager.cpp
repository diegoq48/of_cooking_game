#include "EntityManager.h"
// Manages all of the entities in the game and updates them

void EntityManager::tick(){
    for(unsigned int i=0; i<entities.size(); i++){
        entities[0]->tick();
    }
    if(firstClient != nullptr){
        firstClient->tick();
    }
    removeLeavingClients();
}

void EntityManager::removeLeavingClients(){
    // Remove all clients that are leaving
    Client* tempClient = firstClient;
    Client* prevClient = nullptr;
    
    while(tempClient != nullptr){
        if(tempClient->isLeaving || tempClient->isServed){
            if (tempClient->isLeaving){
                leftClients++;
                std::cout << "Left clients: " << leftClients << std::endl;
                inspector* tempInspector = dynamic_cast<inspector*>(tempClient);
                if (tempInspector != nullptr){
                    inspectorsThatLeft++;
                    std::cout << "Inspectors that left: " << inspectorsThatLeft << std::endl;
                } 
            }
                else {
                    servedClients++;
                    std::cout << "Client served" << servedClients << std::endl;

                }

            if(prevClient == nullptr){
                firstClient = tempClient->nextClient;
                delete tempClient;
                tempClient = firstClient;
            }else{
                prevClient->nextClient = tempClient->nextClient;
                delete tempClient;
                tempClient = prevClient->nextClient;
            }
        }else{
            prevClient = tempClient;
            tempClient = tempClient->nextClient;
        }
    }
}

// Equivilent to the draw function in ofApp
void EntityManager::render(){
    for(unsigned int i=0; i<entities.size(); i++){
        entities[i]->render();
    }
    if(firstClient != nullptr){
        firstClient->render();
    }
}
// Adds an entity to the list of all global entities in the game
void EntityManager::addEntity(Entity *e){
    entities.push_back(e);
}


// adds a client to the list of clients a linked list 
void EntityManager::addClient(Client* c){
    if(firstClient == nullptr){
        firstClient = c;
    }else{
        Client* tempClient = firstClient;
        tempClient->setY(tempClient->getY()+72);
        while(tempClient->nextClient!=nullptr){
            tempClient = tempClient->nextClient;
            tempClient->setY(tempClient->getY()+72);

        }
        tempClient->nextClient = c;
    }
}

void EntityManager::reset(){
   //delete all cleints and entities
   std::cout << "Resetting EntityManager" << std::endl;
   leftClients = 0;
    entities.clear();
    Client* tempClient = firstClient;
    Client* prevClient = nullptr;
    while(tempClient != nullptr){
        prevClient = tempClient;
        tempClient = tempClient->nextClient;
        delete prevClient;
    }
    firstClient = nullptr;
    
}
// returns the number of clients in the linked list
int EntityManager::countClients(){
    int count = 0;
    Client* current = firstClient;
    while (current != nullptr) {
        count++;
        current = current->nextClient;
    }
    return count;

}