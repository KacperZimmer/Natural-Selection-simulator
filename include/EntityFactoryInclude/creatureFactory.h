//
// Created by Kacper Zimmer on 21/12/2023.
//

#ifndef EXAMPLE_CREATUREFACTORY_H
#define EXAMPLE_CREATUREFACTORY_H


#include "entityFactory.h"

class CreatureFactory : public entityFactory{
public:
    std::unique_ptr<Creature> prepareOne() override;
};



#endif //EXAMPLE_CREATUREFACTORY_H
