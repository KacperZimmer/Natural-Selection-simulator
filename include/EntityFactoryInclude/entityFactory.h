#ifndef EXAMPLE_ENTITYFACTORY_H
#define EXAMPLE_ENTITYFACTORY_H

#include "../CreatureIncludes/creature.h"

class entityFactory {
public:
    virtual std::unique_ptr<Creature> prepareOne(float xPos, float yPos, float size, float speed, float seeingRange) = 0;
    virtual std::unique_ptr<Creature> generateAccordingToGenome() = 0;

    float creatureRadius{};
    float seeingRange{};
    float speed{};
    Vector2 basePosition{};

    std::unique_ptr<Creature> create(float xPos, float yPos, float size, float speed, float seeingRange) {
        std::unique_ptr<Creature> get = (prepareOne(xPos, yPos, size,speed,seeingRange));
        return get;
    }


    virtual ~entityFactory() {}
};

#endif // EXAMPLE_ENTITYFACTORY_H
