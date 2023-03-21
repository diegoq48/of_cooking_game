#include "Client.h"

class inspector : public Client {
private:
    int patience = 3000;
    int costOfLeave = rand() % 100 + 1;
public:
    inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger) : Client(x, y, width, height, sprite, burger){
    }
    int serve(){
        if (this->burger->equals(this->burger)){
            isServed = true;
            return 10;
        }
        else{
            isLeaving = true;
        }
        if(nextClient == nullptr){
            return costOfLeave *-1;
        }
        nextClient->serve(this->burger);
        return costOfLeave *-1;
    }
};