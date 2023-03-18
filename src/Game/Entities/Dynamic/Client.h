#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    protected:
        Burger* burger;
        int patience = 3600;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        virtual int serve(Burger*);
        Burger* getBurger(){ return burger; }
        Client* nextClient=nullptr;
        bool isLeaving=false;
        bool isServed=false;



};