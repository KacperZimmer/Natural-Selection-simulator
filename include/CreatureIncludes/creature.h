
#ifndef EXAMPLE_CREATURE_H
#define EXAMPLE_CREATURE_H
#include <iostream>

#include "../constantValues.h"
#include "raylib.h"
#include "movement.h"
#include "seeing.h"

#include "foodInclude/foodContainer.h"


class Creature {
private:
    Vector2 basePosition{100, 200};
    float radiusCreature{};
    float moveSpeed{1.f};
    float seeingRadius{20.f};
    Movement movement{0.f};
    Seeing eyes{{}};
    double energy{1000};

public:


    Creature(float x, float y, float radius) : radiusCreature{radius}{
        movement.setCreatureRadius(this->radiusCreature);
        movement.setInitialCreaturePosVector(x,y);

    }

    double getEnergy() const;

    double calcEnergyLoss() const;
    void render();
    void turnOnVision();
    void update(const FoodContainer& foodContainer);
};


#endif //EXAMPLE_CREATURE_H
