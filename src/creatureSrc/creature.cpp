#include "../../include/CreatureIncludes/creature.h"


void Creature::turnOnVision() {
    bool currentState = !this->eyes.ShouldDisplayVisionRange();
    this->eyes.setShouldDisplayVisionRange(currentState);


}
void Creature::render() {

    this->movement.move();
    this->eyes.setHightlightPositionVector(this->movement.getPosition());

    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();
    }
    DrawCircle(static_cast<int>(movement.getPosition().x), static_cast<int>(movement.getPosition().y),this->radiusCreature, BLUE);
}







