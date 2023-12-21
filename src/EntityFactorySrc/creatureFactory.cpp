
#include "../../include/EntityFactoryInclude/creatureFactory.h"

std::unique_ptr<Creature> CreatureFactory::prepareOne() {
    return std::make_unique<Creature>(100,100,10);
}
