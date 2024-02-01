#include "../../include/CreatureIncludes/creature.h"
#include <cmath>


void Creature::turnOnVision() {
    /*
     * Turns on the vision range for each character
     */

    bool currentState = !this->eyes.ShouldDisplayVisionRange();
    this->eyes.setShouldDisplayVisionRange(currentState);

}

void Creature::render() {

    DrawCircle(static_cast<int>(movement.getPosition().x), static_cast<int>(movement.getPosition().y),this->radiusCreature, this->currentColor);
}

double Creature::calcEnergyLoss() const {

    //kinetic energy formula scaled by 700 factor
    return (pow(this->radiusCreature, 3) * pow(this->moveSpeed,2) ) / 700;
}

double Creature::getEnergy() const {

    return energy;
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
    }else if(this->foodConsumed >= 1){
        movement.goToTarget(movement.getClosestPathToBoundaryVector());
    }else{
        this->movement.move();
    }


    this->updateEnergy();
}

void Creature::die() {
    this->isAlive = false;
    this->currentColor = this->deathColor;
}

void Creature::updateEnergy() {
    this->energy -= calcEnergyLoss();
}

void Creature::updateMovement(size_t nearestFoodIndex,FoodContainer& foodContainer) {

    Vector2 currentPathEndPoint = foodContainer.getVectorAtIndex(nearestFoodIndex);


    if(!this->movement.checkIfTargetIsReached(currentPathEndPoint)){
        movement.goToTarget(currentPathEndPoint);
    }else{
        this->energy += 500;
        foodContainer.deleteFood(nearestFoodIndex);
        ++this->foodConsumed;
    }

//    if(this->movement.goToTarget(foodContainer.getVectorAtIndex(nearestFoodIndex))){
//
//        foodContainer.deleteFood(nearestFoodIndex);
//        this->energy += 500;
//        ++this->foodConsumed;
//    }

    if(foodConsumed == 2){
        this->reproductionStatus = true;
    }

}

void Creature::updateVision() {

    this->eyes.setHightlightPositionVector(this->movement.getPosition());

    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();

    }
}

void Creature::setMovement(Movement &movement) {
    this->movement = movement;

}

void Creature::setSeeing(Seeing &eyes) {
    this->eyes = eyes;
}

bool Creature::isDead() const {
    return !this->isAlive;
}

bool Creature::shouldReproduce() {
    return this->shouldReproduce();
}







