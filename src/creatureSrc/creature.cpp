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
        this->isAlive = false;
        this->currentColor = this->deathColor;
        return;
    }



    this->eyes.setHightlightPositionVector(this->movement.getPosition());


    int nearestFoodPosition = this->eyes.isFoodInRange(foodContainer.getFoodArray());

    if(nearestFoodPosition == -1){
        this->movement.move();

    }else if(this->movement.goToTarget(foodContainer.getVectorAtIndex(nearestFoodPosition))){

        foodContainer.deleteFood(nearestFoodPosition);
        this->energy += 500;
    }

    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();

    }

    this->energy -= calcEnergyLoss();

}







