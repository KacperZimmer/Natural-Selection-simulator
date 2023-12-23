#ifndef EXAMPLE_CREATUREFACTORY_H
#define EXAMPLE_CREATUREFACTORY_H


#include "entityFactory.h"

class CreatureFactory : public entityFactory{
public:

    bool hasParent{};
    std::unique_ptr<Creature> prepareOne(float xPos, float yPos, float size, float speed, float seeingRange) override;

};

#endif //EXAMPLE_CREATUREFACTORY_H
