
#ifndef EXAMPLE_MOVABLE_H
#define EXAMPLE_MOVABLE_H


#include <raylib.h>

class Movable {

protected:
    Vector2 lastLegalPosition{};
    Vector2 currentPosition{};
    float deltaTime{};
    float shouldUpdatePosition{};
    float timeAfterPositionShouldBeUpdated{1.f/1.3f};
    float creatureRadius{};

    void goBackToLegalPositionIfOutOfBound();


public:

    virtual void move() = 0;
    virtual void goToTarget(const Vector2& target) = 0;
    virtual bool checkIfTargetIsReached(Vector2 target) = 0;
    virtual ~Movable();
};


#endif //EXAMPLE_MOVABLE_H
