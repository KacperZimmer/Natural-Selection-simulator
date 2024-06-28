
#ifndef EXAMPLE_MOVABLE_H
#define EXAMPLE_MOVABLE_H


#include <raylib.h>


class Movable {

protected:
    Vector2 lastLegalPosition{};
    Vector2 currentPosition{};
    float creatureRadius{};
    float speed{};

    void goBackToLegalPositionIfOutOfBound();

    Movable(float creatureRadius, float speed);

public: // methods

    const Vector2& getPosition() const;
    Vector2 getClosestPathToBoundaryVector() const;
    virtual void move() = 0;
    virtual void goToTarget(const Vector2& target) = 0;
    virtual bool checkIfTargetIsReached(Vector2 target) = 0;
    void setInitialCreaturePosVector(float x, float y);

    virtual ~Movable();
};


#endif
