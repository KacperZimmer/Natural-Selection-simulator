
#ifndef EXAMPLE_CREATURE_H
#define EXAMPLE_CREATURE_H
#include "raylib.h"
#include <raymath.h>
#include "constantValues.h"


class Creature {
private:
    Vector2 lastLegalPositon{};
    Vector2 creaturePosVector{};
    Vector2 basePosition{100, 200};
    float radiusCreature{};
    float moveSpeed{1.f};
    float seeingRadius{20.f};
    float shouldUpdate{0.f};
    float timeConst{1.f/1.5f};
    int xDirection{1};
    int yDirection{1};

    int randomCoord();
    bool isOutOfBound();
    void visualizeSeeing(bool shouldRender);
    void manageLifeCycle(bool renderSeeing);
    void goToTarget(Vector2 vector);

public:

    Creature(){

    }
    Creature(float x, float y, float radius) : radiusCreature{radius}, creaturePosVector{x,y}{}

    //setters
    void setyPos(float y);
    void setxPos(float y);
    void setxAndY(float x, float y);

    //getters
    const Vector2 &getCreaturePosVector() const;

    void render(bool highlightVision);
    void move();


};


#endif //EXAMPLE_CREATURE_H
