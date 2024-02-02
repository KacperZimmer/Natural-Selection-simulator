
#include "../../include/CreatureIncludes/movement.h"
#include "raymath.h"
#include <random>
#include <iostream>
#include <cfloat>

const Vector2& Movement::getPosition() const {

    return this->currentPosition;
}

void Movement::move() {

    /*
     * Updates player position after some time
     */

    goBackToLegalPositionIfOutOfBound();

    this->shouldUpdatePosition += deltaTime;

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

void Movement::goToTarget(const Vector2& target) {


    if(!checkIfTargetIsReached(target)) {
        //TODO violates single resp, function takes player to the target and checks if return whether he reached the target
        Vector2 direction = Vector2Normalize(Vector2Subtract(target, this->currentPosition));


        this->currentPosition.x += direction.x * this->speedFactor;
        this->currentPosition.y += direction.y * this->speedFactor;
    }


}

void Movement::setCreatureRadius(float creatureRadius) {
    /*  sets initial radius of character
     *  which is crucial for later movement calculations
     * */
   this->creatureRadius = creatureRadius;
}

void Movement::setInitialCreaturePosVector(float x, float y) {
    this->currentPosition.x = x;
    this->currentPosition.y = y;
}

Vector2 Movement::getClosestPathToBoundaryVector() const{


    Vector2 closestPoint{};


    float shortestPath = FLT_MAX;
    float current_x_pos = this->creatureRadius, current_y_pos = this->creatureRadius;

    float y_spacing = 1;
    float x_spacing = 1;

    for(short i = 0; i < 4; i++){

        for(int j = 0; j < SCREEN_WIDTH - this->creatureRadius * 2; ++j){

            Vector2 currentPositionToCheck{current_x_pos, current_y_pos};

            float distanceToTheGivenPoint = Vector2Distance(this->currentPosition,currentPositionToCheck);

            if(shortestPath > distanceToTheGivenPoint){
                closestPoint.x = current_x_pos;
                closestPoint.y = current_y_pos;
                shortestPath = distanceToTheGivenPoint;
            }


            switch (i){
                case 0:
                    current_x_pos += x_spacing;
                    break;

                case 1:
                    current_y_pos += y_spacing;
                    break;

                case 2:
                    current_x_pos -= x_spacing;
                    break;

                case 3:
                    current_y_pos -= y_spacing;
                    break;

                default:
                    break;
            }
        }
    }
    return closestPoint;
}

Movement::Movement(float radius, float speed) {
    this->creatureRadius = radius;
    this->speedFactor = speed;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0169255, 0.05);
    this->deltaTime = dis(gen);
}

Movement::Movement() {

}

bool Movement::checkIfTargetIsReached(Vector2 target) {
    if(Vector2Distance(this->currentPosition, target) <= this->creatureRadius){
        return true;
    }
    return false;
}



