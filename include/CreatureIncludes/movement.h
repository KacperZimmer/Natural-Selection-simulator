
#ifndef EXAMPLE_MOVEMENT_H
#define EXAMPLE_MOVEMENT_H
#include "../constantValues.h"
#include "../../include/constantValues.h"
#include "raylib.h"
#include <vector>
#include <random>

class Movement {
private:
    Vector2 lastLegalPosition;
    Vector2 currentPosition;
    float creatureRadius{};
    float shouldUpdatePosition{};
    float timeAfterPositionShouldBeUpdated{1.f/1.3f};
    float deltaTime;
    int speedFactor{2};
    int xDirection{1};
    int yDirection{1};

    void goBackToLegalPositionIfOutOfBound();
    int generateRandomDirection() const;

public:
    const Vector2& getPosition() const;
    Movement(float radius, float speed){
        this->creatureRadius = radius;
        this->speedFactor = speed;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0169255, 0.05);
        this->deltaTime = dis(gen);
    }
    Movement(){


    }
    void move();
    void setCreatureRadius(float creatureRadius);
    void setInitialCreaturePosVector(float x, float y);
    bool goToTarget(const Vector2& target);
};


#endif //EXAMPLE_MOVEMENT_H
