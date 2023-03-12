#include "Table.h"

Table::Table(int x, int y, int width, int height, int seatNumber,  ofImage seatSprite, ofImage tableSprite ) : Entity(x, y, width, height, tableSprite){

    // initialize the table and the sits
    this->seatSprite = seatSprite;
    this->seatNumber = seatNumber;
    this->tableSprite = tableSprite;
    for (int i = 0; i < seatNumber; i++){
        seats.push_back(new Entity((x+36)  + 40*cos(2 * PI * i / this->seatNumber), (y+50)  + 45*sin(2 * PI * i / this->seatNumber), 34, 37, seatSprite));
    }
}


void Table::render(){
    ofSetColor (255,255,255);
    for (int i = 0; i < seats.size(); i++){
        seats[i]->render();
     }
     tableSprite.draw(x, y, width, height);

}

