
#ifndef EXAMPLE_MOVEMENT_H
#define EXAMPLE_MOVEMENT_H
#include "constantValues.h"
#include "raylib.h"
#include "raymath.h"

class Movement {
private:
    Vector2 lastLegalPosition{};
    Vector2 currentPosition{};
    float creatureRadius{};
    float shouldUpdatePosition{};
    float timeAfterPositionShouldBeUpdated{1.f/2.f};
    float deltaTime{};
    int xDirection{1};
    int yDirection{1};



    void move();
    void goToTarget(Vector2 target);

    bool isOutOfBound();
    void goBackToLegalPositionIfOutOfBound();

    int generateRandomDirection();


public:
    const Vector2& getPosition() const;
};


#endif //EXAMPLE_MOVEMENT_H
