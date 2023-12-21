
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
    Movement movement;
    Seeing eyes;
    double energy{1000};

public:


    Creature(float x, float y, float radius, float speed, float seeingRange) : radiusCreature{radius}{

//        this->movement = {};
//
//        this->eyes = {this->movement.getPosition(), this->seeingRadius};
//        movement.setCreatureRadius(this->radiusCreature);
//        movement.setInitialCreaturePosVector(x,y);

    }
    Creature(){

    }
    double getEnergy() const;
    double calcEnergyLoss() const;
    void render();
    void turnOnVision();
    void update(FoodContainer& foodContainer);

    void setMovement(Movement& movement){
        this->movement = movement;
    }
    void setSeeing(Seeing& eyes){
        this->eyes = eyes;
    }

};


#endif
