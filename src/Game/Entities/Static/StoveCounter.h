#include "BaseCounter.h"

// Things that should contain the class
// 1.Bar that incrents with the timer
// 2. Should have two states, cookeeed and uncooked
// 3. It should play a sound when it is done cooking


class StoveCounter : public BaseCounter {
private:
    int cookTime = 0;
    int cookTimeMax = 0;
    bool isCooking = false;
    bool isCooked = false;
    


public:
    StoveCounter(int x, int y, int width, int height, Ingredient* item, ofImage sprite, int cookTimeMax) : BaseCounter(x, y, width, height, item, sprite) {
        this->cookTimeMax = cookTimeMax;
        cookTime = 0;
        cookTimeMax = 800;
        canGrab = false;
    }
    void startCooking();

    void drawCookingBar();

    void tick();
    void setIsCooking(bool sett);
    bool getIsCooking();
    void setisCooked(bool sett);
    bool getisCooked();
    void showItem();

};