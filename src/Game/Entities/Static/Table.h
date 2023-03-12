#include "Entity.h"

class Table : public Entity{
public:
    Table(int x, int y, int width, int height, int seatNumber, ofImage seatSprite, ofImage tableSprite );
    void render();
private:
    int seatNumber;
    ofImage tableSprite;
    ofImage seatSprite;
    vector<Entity*> seats;
};
