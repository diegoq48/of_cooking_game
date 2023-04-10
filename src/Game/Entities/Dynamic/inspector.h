#include "Client.h"
// inspector subclass of client implemented lazily
class inspector : public Client {
private:
    int patience = 3000;
public:
    inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger) : Client(x, y, width, height, sprite, burger){
    }
};