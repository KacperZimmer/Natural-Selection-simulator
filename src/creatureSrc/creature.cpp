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
    //kinetic energy formula scaled by scale factor
    return (pow(this->radiusCreature, 3) * pow(this->moveSpeed,2) ) / 700;
}

double Creature::getEnergy() const {
    return energy;
}

void Creature::update(FoodContainer& foodContainer) {
    this->eyes.setHightlightPositionVector(this->movement.getPosition());


    //TODO consider using state design pattern in futurex
    int nearestFoodPosition = this->eyes.isFoodInRange(foodContainer.getFoodArray());
    //TODO change the name of function below is not obvious what it does

    if(nearestFoodPosition == -1){
        this->movement.move();
        std::cout << "i am moving " << std::endl;

    }else if(this->movement.goToTarget(foodContainer.getVectorAtIndex(nearestFoodPosition))){

        foodContainer.deleteFood(nearestFoodPosition);
    }

    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();

    }
    this->energy -= calcEnergyLoss();



}







