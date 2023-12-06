#include <random>
#include <iostream>
#include "../../include/CreatureIncludes/creature.h"
#include "../../include/constantValues.h"


void Creature::render(bool highlightVision) {

    movement.move();
    eyes.setHightlightPositionVector(this->movement.getPosition());

    if(!eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();
        std::cout << "here" << std::endl;
    }
    DrawCircle(movement.getPosition().x, movement.getPosition().y,this->radiusCreature, BLUE);
}

void Creature::turnOnVision() {
    bool currentState = !this->eyes.isShouldDisplayVisionRange();
    std::cout << currentState << std::endl;
    this->eyes.setShouldDisplayVisionRange(currentState);
}






