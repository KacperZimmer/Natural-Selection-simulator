
#include "../../include/EntityFactoryInclude/creatureFactory.h"

std::unique_ptr<Creature> CreatureFactory::prepareOne(float xPos, float yPos, float size, float speed, float seeingRange) {

    std::unique_ptr<Creature> creature = std::make_unique<Creature>(xPos, yPos,size, speed, seeingRange);

    Movement movement{size, speed};
    movement.setInitialCreaturePosVector(xPos, yPos);
    Seeing seeing{movement.getPosition(), seeingRange};

    creature->setMovement(movement);
    creature->setSeeing(seeing);

//    return std::make_unique<Creature>(xPos, yPos, size);

    return creature;
}
