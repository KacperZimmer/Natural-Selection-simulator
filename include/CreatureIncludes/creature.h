
#ifndef EXAMPLE_CREATURE_H
#define EXAMPLE_CREATURE_H

#include "movement.h"
#include "seeing.h"
#include "../CreatureIncludes/Genome.h"

#include "../foodInclude/foodContainer.h"


class Creature {
private:
    //TODO make code less
    //TODO tightly coupled

    std::unique_ptr<Movable> movement;
    Seeing eyes;

    Genome genome;
    Color currentColor{BLUE};
    Color deathColor{BLACK};

    size_t foodConsumed{};

    double startingEnergy{5000};
    bool reproductionStatus{false};
    bool isAlive{true};
    bool sleeping{false};

    double calcEnergyLoss() const;
    void die();
    void updateEnergy();
    void updateMovement(size_t nearestFoodIndex, FoodContainer& foodContainer);
    void updateVision();
    void headToSleep(Vector2 target);
    bool checkIfShouldReproduce() const;
    void sleep();

public:

    //constructors
    Creature(Vector2 coord ,float radius, float speed, float seeingRange) : genome{speed,seeingRange,5000,radius}
    {
    };
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
