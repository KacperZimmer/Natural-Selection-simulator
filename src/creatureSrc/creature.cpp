#include "../../include/CreatureIncludes/creature.h"
#include <cmath>



void Creature::turnOnVision() {
    /*
     * Turns on the vision range for each character
     */

    bool currentState = this->eyes.ShouldDisplayVisionRange();

    if(currentState == false){
        this->eyes.setShouldDisplayVisionRange(!currentState);
    }

}

void Creature::turnOffVision() {
    //TODO both turn off and turn on can be made into one function

    bool currentState = this->eyes.ShouldDisplayVisionRange();

    if(currentState == true){
        this->eyes.setShouldDisplayVisionRange(!currentState);
    }
}

void Creature::render() {

    DrawCircle(static_cast<int>(movement->getPosition().x), static_cast<int>(movement->getPosition().y),this->radiusCreature, this->currentColor);
}

double Creature::calcEnergyLoss() const {

    //kinetic energy formula scaled by 700 factor
    return (pow(this->radiusCreature, 3) * pow(this->moveSpeed,2) ) / 700;
}



void Creature::headToSleep(Vector2 target) {

    if(!this->movement->checkIfTargetIsReached(target)) {
        movement->goToTarget(movement->getClosestPathToBoundaryVector());
        this->updateEnergy();

    }else{
        this->sleeping = true;
    }
}


void Creature::die() {
    this->isAlive = false;
    this->currentColor = this->deathColor;
}



void Creature::update(FoodContainer& foodContainer) {

    if(this->energy <= 0){
        die();
        return;
    }
    this->updateVision();

    size_t nearestFoodInVectorIndex = this->eyes.isFoodInRange(foodContainer.getFoodArray());

    if(nearestFoodInVectorIndex != -1){
        this->updateMovement(nearestFoodInVectorIndex,foodContainer);

    }else if(this->sleeping == true){
        this->reproductionStatus =true;

    }else if(this->foodConsumed >= 1){
        this->headToSleep(movement->getClosestPathToBoundaryVector());

    }else{
        this->movement->move();
        this->updateEnergy();

    }

}

void Creature::updateEnergy() {
    this->energy -= calcEnergyLoss();
}

void Creature::updateMovement(size_t nearestFoodIndex,FoodContainer& foodContainer) {

    Vector2 currentPathEndPoint = foodContainer.getVectorAtIndex(nearestFoodIndex);


    if(!this->movement->checkIfTargetIsReached(currentPathEndPoint)){
        movement->goToTarget(currentPathEndPoint);
    }else{
        this->energy += 500;
        foodContainer.deleteFood(nearestFoodIndex);
        ++this->foodConsumed;
    }

    this->updateEnergy();

}

void Creature::updateVision() {

    this->eyes.setHightlightPositionVector(this->movement->getPosition());

    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();
    }

}


void Creature::setMovement(std::unique_ptr<Movable>& movement) {
    this->movement = std::move(movement);

}

void Creature::setSeeing(Seeing &eyes) {
    this->eyes = eyes;
}

bool Creature::isDead() const {
    return !this->isAlive;
}

bool Creature::shouldReproduce() const {
    return this->reproductionStatus;
}



const Vector2& Creature::getPosition() const{
    return this->movement->getPosition();
}

float Creature::getRadius() const{
    return this->radiusCreature;
}

float Creature::getSpeed() const {
    return this->moveSpeed;
}

float Creature::seeingRange() const{
    return this->eyes.getSeeingRange();
}

bool Creature::isSleeping() const {
    return this->sleeping;
}

void Creature::wakeUp() {
    this->foodConsumed = 0;
    this->sleeping = false;
}













