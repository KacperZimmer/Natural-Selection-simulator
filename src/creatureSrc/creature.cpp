#include "../../include/CreatureIncludes/creature.h"
#include <cmath>


void Creature::turnOnVision() {

    bool currentState = !this->eyes.ShouldDisplayVisionRange();
    this->eyes.setShouldDisplayVisionRange(currentState);

}

void Creature::render() {

    DrawCircle(static_cast<int>(movement.getPosition().x), static_cast<int>(movement.getPosition().y),this->radiusCreature, this->currentColor);
}

double Creature::calcEnergyLoss() const {

    //kinetic energy formula scaled by scale factor
    return (pow(this->radiusCreature, 3) * pow(this->moveSpeed,2) ) / 700;
}

double Creature::getEnergy() const {

    return energy;
}

void Creature::update(FoodContainer& foodContainer) {

    // TODO consider using state design pattern in future
    if(this->energy <= 0){
        die();
        return;
    }
    this->updateVision();

    long long nearestFoodPositioninSeeingRange = this->eyes.isFoodInRange(foodContainer.getFoodArray());

//    switch(nearestFoodPositioninSeeingRange){
//
//        case -1:
//            this->updateMovement(nearestFoodPositioninSeeingRange);
//            break;
//
//        default:
//            this->updateMovement(nearestFoodPositioninSeeingRange, foodContainer);
//            break;
//    }

    this->updateEnergy();
}

void Creature::die() {
    this->isAlive = false;
    this->currentColor = this->deathColor;
}

void Creature::updateEnergy() {
    this->energy -= calcEnergyLoss();
}

void Creature::updateMovement(size_t nearestFoodPositioninSeeingRange) {
    if(nearestFoodPositioninSeeingRange == -1){
        this->movement.move();

    }

}

void Creature::updateMovement(size_t nearestFoodIndex,FoodContainer& foodContainer) {
    if(this->movement.goToTarget(foodContainer.getVectorAtIndex(nearestFoodIndex))){

        foodContainer.deleteFood(nearestFoodIndex);
        this->energy += 500;
    }

}

void Creature::updateVision() {

    this->eyes.setHightlightPositionVector(this->movement.getPosition());

    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();

    }
}







