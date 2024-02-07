
#ifndef EXAMPLE_CREATURE_H
#define EXAMPLE_CREATURE_H

#include "movement.h"
#include "seeing.h"

#include "../foodInclude/foodContainer.h"


class Creature {
private:
    //TODO make code less
    // tightly coupled by using interfaces in near future

    std::unique_ptr<Movable> movement;
    Seeing eyes;

    Color currentColor{BLUE};
    Color deathColor{BLACK};

    size_t foodConsumed{};

    float radiusCreature{};
    float moveSpeed;

    double startingEnergy{5000};
    double energy{5000};

    bool reproductionStatus{false};
    bool isAlive{true};
    bool sleeping{false};

    double calcEnergyLoss() const;
    void die();
    void updateEnergy();
    void updateMovement(size_t nearestFoodIndex, FoodContainer& foodContainer);
    void updateVision();
    void headToSleep(Vector2 target);
    void sleep();

public:

    //constructors
    Creature(float x, float y, float radius, float speed, float seeingRange) : radiusCreature{radius}, moveSpeed{speed}
    {};
    Creature(){};

    //public methods
    void render();
    void turnOnVision();
    void update(FoodContainer& foodContainer);
    void wakeUp();
    void turnOffVision();


    // setters
    void setMovement(std::unique_ptr<Movable>& movement);
    void setSeeing(Seeing& eyes);
    //getters
    bool shouldReproduce() const;
    bool isDead() const;
    bool isSleeping() const;
    float getRadius() const;
    float getSpeed() const;
    float seeingRange() const;

    const Vector2& getPosition() const;
    double getEnergy() const;
};


#endif
