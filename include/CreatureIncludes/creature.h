
#ifndef EXAMPLE_CREATURE_H
#define EXAMPLE_CREATURE_H
#include <iostream>

#include "movement.h"
#include "seeing.h"

#include "../foodInclude/foodContainer.h"


class Creature {
private:
    bool isAlive{true};
    Color currentColor{BLUE};
    Color deathColor{BLACK};
    float radiusCreature{};
    float moveSpeed;
    Movement movement;
    Seeing eyes;
    double energy{1000};

    double calcEnergyLoss() const;

public:


    Creature(float x, float y, float radius, float speed, float seeingRange) : radiusCreature{radius}, moveSpeed{speed}{
    };
    Creature(){};

    double getEnergy() const;
    void render();
    void turnOnVision();
    void update(FoodContainer& foodContainer);
    void setMovement(Movement& movement){
        this->movement = movement;
    }
    void setSeeing(Seeing& eyes){
        this->eyes = eyes;
    }

    bool isDead(){
        return !this->isAlive;
    }



};


#endif
