#ifndef EXAMPLE_ENTITYFACTORY_H
#define EXAMPLE_ENTITYFACTORY_H

#include "../CreatureIncludes/creature.h"
#include "raymath.h"
#include <memory>

class entityFactory {
public:
    virtual std::unique_ptr<Creature> prepareOne() = 0;

    float creatureRadius{};
    float seeingRange{};
    float speed{};
    Vector2 basePosition{};

    std::unique_ptr<Creature> create() {
        std::unique_ptr<Creature> get = (prepareOne());
        return get;
    }

    virtual ~entityFactory() {}
};

#endif // EXAMPLE_ENTITYFACTORY_H
