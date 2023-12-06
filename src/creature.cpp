#include <random>
#include <iostream>
#include "../include/creature.h"
#include "../include/constantValues.h"


void Creature::setxAndY(float x, float y) {
    this->creaturePosVector.x = x;
    this->creaturePosVector.y = y;


}
void Creature::setyPos(float y) {
    this->creaturePosVector.y = y;

}
void Creature::setxPos(float x) {
    this->creaturePosVector.x = x;
}
int Creature::randomCoord() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    int result = dis(gen);
    return (result == 0) ? -1 : 1;
}


void Creature::move(){
    //TODO clean up the code

//    seeingV();

    float getDeltatime = GetFrameTime();
//    const float timeConst = 1.f/2.f;
//    static float shouldUpdate = 0.f;


    if(!isOutOfBound()){
        this->lastLegalPositon = this->creaturePosVector;
    }
    else{
        this->creaturePosVector = lastLegalPositon;
    }
    this->shouldUpdate += getDeltatime;



    if(this->shouldUpdate >= this->timeConst){

        xDirection *= randomCoord();
        yDirection *= randomCoord();

        this->shouldUpdate = 0.f;
    }else{
        this->creaturePosVector.x += static_cast<float>(2 * xDirection);
        this->creaturePosVector.y += static_cast<float>(2 * yDirection);
    }

}

void Creature::render(bool highlightVision) {
    manageLifeCycle(highlightVision);

}

const Vector2 &Creature::getCreaturePosVector() const {
    return creaturePosVector;
}

bool Creature::isOutOfBound() {

}

void Creature::goToTarget(Vector2 target) {

    Vector2 direction = Vector2Normalize(Vector2Subtract(target, this->creaturePosVector));
    this->creaturePosVector.x += direction.x * 2;
    this->creaturePosVector.y += direction.y * 2;
}

void Creature::visualizeSeeing(bool shouldRender) {
    if(shouldRender) {
        DrawLine(this->creaturePosVector.x, this->creaturePosVector.y, creaturePosVector.x + 20 * xDirection,
                 creaturePosVector.y + 30 * yDirection, Color{255, 0, 0, 255});
        DrawCircle(this->creaturePosVector.x, this->creaturePosVector.y, 40.f, Color{116, 45, 255, 128});
    }
}

void Creature::manageLifeCycle(bool renderSeeing) {

    /*
     * function takes care of proper rendering parts of the creatures
     * and takes care of behaviour such as detecting food, going to certain target
     */

    DrawCircle(static_cast<int>(this->creaturePosVector.x),static_cast<int>(this->creaturePosVector.y), this->radiusCreature, BLUE);
    move(a);
    visualizeSeeing(renderSeeing);
}
