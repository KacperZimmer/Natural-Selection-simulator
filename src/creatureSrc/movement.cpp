
#include "../../include/CreatureIncludes/movement.h"
#include "raymath.h"
#include <random>

const Vector2& Movement::getPosition() const {

    return this->currentPosition;
}

void Movement::move() {

    goBackToLegalPositionIfOutOfBound();

    this->deltaTime = GetFrameTime();

    this->shouldUpdatePosition += deltaTime;

    if(this->shouldUpdatePosition >= this->timeAfterPositionShouldBeUpdated){
        this->shouldUpdatePosition = 0.f;

        this->xDirection *= this->generateRandomDirection();
        this->yDirection = this->generateRandomDirection();

    }else{
        this->currentPosition.x += static_cast<float>(2 * xDirection);
        this->currentPosition.y += static_cast<float>(2 * yDirection );
    }
}

int Movement::generateRandomDirection() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    int result = dis(gen);
    return (result == 0) ? -1 : 1;
}

bool Movement::isOutOfBound() {
    if(this->currentPosition.x >= SCREEN_WIDTH - this->creatureRadius || this->currentPosition.x <= 0 + this->creatureRadius || this->currentPosition.y >= SCREEN_HEIGHT - this->creatureRadius||this->currentPosition.y <= 0 + this->creatureRadius) return true;
    return false;
}

void Movement::goBackToLegalPositionIfOutOfBound() {
    if(!isOutOfBound()){
        this->lastLegalPosition = currentPosition;
    }else{
        this->currentPosition = lastLegalPosition;
    }
}

void Movement::goToTarget(Vector2 target) {
    Vector2 direction = Vector2Normalize(Vector2Subtract(target, this->currentPosition));

    this->currentPosition.x += direction.x;
    this->currentPosition.y += direction.y;
}

void Movement::setCreatureRadius(float creatureRadius) {
   this->creatureRadius = creatureRadius;
}

void Movement::setInitialCreaturePosVector(float x, float y) {
    this->currentPosition.x = x;
    this->currentPosition.y = y;
}




