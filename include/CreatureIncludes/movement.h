
#ifndef EXAMPLE_MOVEMENT_H
#define EXAMPLE_MOVEMENT_H
#include "../constantValues.h"
#include "../../include/constantValues.h"
#include "raylib.h"
#include "Movable.h"
#include <vector>
#include <random>

class Movement : public Movable{
private:

    int xDirection{1};
    int yDirection{1};
    int speedFactor{2};
    int generateRandomDirection() const;

public:
    const Vector2& getPosition() const;
    Movement(float radius, float speed);



    Movement();
    void move() override;
    void goToTarget(const Vector2& target) override;
    bool checkIfTargetIsReached(Vector2 target) override;

    void setInitialCreaturePosVector(float x, float y);
    Vector2 getClosestPathToBoundaryVector() const;


};


#endif //EXAMPLE_MOVEMENT_H
