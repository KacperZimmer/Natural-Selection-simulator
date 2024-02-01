
#ifndef EXAMPLE_CREATURE_H
#define EXAMPLE_CREATURE_H

#include "movement.h"
#include "seeing.h"

#include "../foodInclude/foodContainer.h"


class Creature {
private:
    bool isAlive{true};
    size_t foodConsumed{};
    Color currentColor{BLUE};
    Color deathColor{BLACK};
    float radiusCreature{};
    float moveSpeed;
    Movement movement;
    Seeing eyes;
    double startingEnergy{5000};
    double energy{5000};

    double calcEnergyLoss() const;
    void die();
    void updateEnergy();
    void updateMovement(size_t nearestFoodPositioninSeeingRange);
    void updateMovement(size_t nearestFoodIndex, FoodContainer& foodContainer);
    void updateVision();
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

    bool isDead() const{
        return !this->isAlive;
    }



};


#endif
