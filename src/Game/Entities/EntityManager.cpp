#include "EntityManager.h"

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
void EntityManager::render(){
    for(unsigned int i=0; i<entities.size(); i++){
        entities[i]->render();
    }
    if(firstClient != nullptr){
        firstClient->render();
    }
}

void EntityManager::addEntity(Entity *e){
    entities.push_back(e);
}

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
