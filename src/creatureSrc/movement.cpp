
#include "../../include/CreatureIncludes/movement.h"
#include "raymath.h"
#include <random>
#include <iostream>
#include <cfloat>

const Vector2& Movement::getPosition() const {

    return this->currentPosition;
}

void Movement::move() {

    goBackToLegalPositionIfOutOfBound();



    this->shouldUpdatePosition += deltaTime;
            ;

    if(this->shouldUpdatePosition >= this->timeAfterPositionShouldBeUpdated){
        this->shouldUpdatePosition = 0.f;

        this->xDirection *= this->generateRandomDirection();
        this->yDirection *= this->generateRandomDirection();

    }else{
        this->currentPosition.x += static_cast<float>(this->speedFactor * xDirection);
        this->currentPosition.y += static_cast<float>(this-> speedFactor * yDirection );
    }
}

int Movement::generateRandomDirection() const{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    int result = dis(gen);
    return (result == 0) ? -1 : 1;
}




void Movement::goBackToLegalPositionIfOutOfBound() {

    auto isNotInBounds = [this](){
        return this->currentPosition.x >= SCREEN_WIDTH - this->creatureRadius || this->currentPosition.x <= 0 + this->creatureRadius || this->currentPosition.y >= SCREEN_HEIGHT - this->creatureRadius||this->currentPosition.y <= 0 + this->creatureRadius;
    };

    if(!isNotInBounds()){
        this->lastLegalPosition = currentPosition;
    }else{
        this->currentPosition = lastLegalPosition;
    }
}

bool Movement::goToTarget(const Vector2& target) {

    Vector2 direction = Vector2Normalize(Vector2Subtract(target, this->currentPosition));

    this->currentPosition.x += direction.x * this->speedFactor;
    this->currentPosition.y += direction.y * this->speedFactor;

    if(Vector2Distance(this->currentPosition, target) <= this->creatureRadius){
        return true;
    }
    return false;
}

void Movement::setCreatureRadius(float creatureRadius) {
   this->creatureRadius = creatureRadius;
}

void Movement::setInitialCreaturePosVector(float x, float y) {
    this->currentPosition.x = x;
    this->currentPosition.y = y;
}

void Movement::GoToClosestPathToBoundary() {
    Vector2 closestPoint{};

    float shortestPath = FLT_MAX;
    float current_x_pos = 0, current_y_pos = 0;

    for(int i = 0; i < 4; i++){

        for(int j = 0; j < 100; ++j){
            Vector2 currentPositionToCheck{current_x_pos, current_y_pos};
            shortestPath = std::min(Vector2Distance(currentPositionToCheck, this->currentPosition),shortestPath);

            if(shortestPath > Vector2Distance(currentPositionToCheck, this->currentPosition)){
                closestPoint.x = current_x_pos;
                closestPoint.y = current_y_pos;
            }
        }
    }
}



