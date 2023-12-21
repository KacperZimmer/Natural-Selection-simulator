
#ifndef EXAMPLE_MOVEMENT_H
#define EXAMPLE_MOVEMENT_H
#include "../constantValues.h"
#include "../../include/constantValues.h"
#include "raylib.h"
#include <vector>

class Movement {
private:
    Vector2 lastLegalPosition;
    Vector2 currentPosition;
    Vector2 shortestDistanceFromTarget{};
    float creatureRadius{};
    float shouldUpdatePosition{};
    float timeAfterPositionShouldBeUpdated{1.f/2.f};
    float deltaTime;
    int speedFactor{2};
    int xDirection{1};
    int yDirection{1};

    void goBackToLegalPositionIfOutOfBound();
    int generateRandomDirection() const;

public:
    const Vector2& getPosition() const;
    Movement(float radius){
        this->creatureRadius = radius;
    }
    void move();
    void setCreatureRadius(float creatureRadius);
    void setInitialCreaturePosVector(float x, float y);
    bool goToTarget(const Vector2& target);
};


#endif //EXAMPLE_MOVEMENT_H
