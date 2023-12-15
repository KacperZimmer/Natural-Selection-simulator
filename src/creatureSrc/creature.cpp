#include "../../include/CreatureIncludes/creature.h"
#include <cmath>


void Creature::turnOnVision() {
    bool currentState = !this->eyes.ShouldDisplayVisionRange();
    this->eyes.setShouldDisplayVisionRange(currentState);

}
void Creature::render() {

    DrawCircle(static_cast<int>(movement.getPosition().x), static_cast<int>(movement.getPosition().y),this->radiusCreature, BLUE);
}

double Creature::calcEnergyLoss() const {
    return (pow(this->radiusCreature, 3) * pow(this->moveSpeed,2) ) / 700;
}

double Creature::getEnergy() const {
    return energy;
}

void Creature::update(FoodContainer& foodContainer) {
    //TO DO consider using state design pattern in future
    int nearestFoodPosition = this->eyes.isFoodInRange(foodContainer.getFoodArray());

    if(nearestFoodPosition != -1){
        foodContainer.deleteFood(nearestFoodPosition);
    }

    this->movement.move();
    this->energy -= calcEnergyLoss();
    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();
        this->eyes.setHightlightPositionVector(this->movement.getPosition());

    }


}







