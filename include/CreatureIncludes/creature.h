
#ifndef EXAMPLE_CREATURE_H
#define EXAMPLE_CREATURE_H
#include <iostream>

#include "../constantValues.h"
#include "raylib.h"
#include "movement.h"
#include "seeing.h"



class Creature {
private:
    Vector2 basePosition{100, 200};
    float radiusCreature{};
    float moveSpeed{1.f};
    float seeingRadius{20.f};
    Movement movement{0.f};
    Seeing eyes{{}};

public:


    Creature(float x, float y, float radius) : radiusCreature{radius}{
        movement.setCreatureRadius(this->radiusCreature);
        movement.setInitialCreaturePosVector(x,y);

    }


    void render();
    void turnOnVision();
};


#endif //EXAMPLE_CREATURE_H
