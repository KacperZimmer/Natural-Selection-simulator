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

void Creature::update(const FoodContainer& foodContainer) {
    this->eyes.isFoodInRange(foodContainer.getFoodArray());
    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();
    }
    this->movement.move();
    this->energy -= calcEnergyLoss();
    this->eyes.setHightlightPositionVector(this->movement.getPosition());


}







