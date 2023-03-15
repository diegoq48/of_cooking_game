#include "Entity.h"
#include "Burger.h"
#include "Restaurant.h"
#include "ofMain.h"

class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience;
        int patience = 3600;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Burger* getBurger(){ return burger; }
        Client* nextClient=nullptr;
        bool isLeaving=false;



};