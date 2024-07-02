#ifndef EXAMPLE_ENTITYFACTORY_H
#define EXAMPLE_ENTITYFACTORY_H

#include "../CreatureIncludes/creature.h"

class entityFactory {
public:
    virtual std::unique_ptr<Creature> prepareOne(float xPos, float yPos, float size, float speed, float seeingRange) = 0;
    virtual std::unique_ptr<Creature> makeChild(const Creature& parenet, Vector2 coord, float radius, float velocity, float seeingRadius) = 0;

    float creatureRadius{};
    float seeingRange{};
    float speed{};
    Vector2 basePosition{};

    std::unique_ptr<Creature> create(float xPos, float yPos, float size, float speed, float seeingRange) {
        std::unique_ptr<Creature> get = (prepareOne(xPos, yPos, size,speed,seeingRange));
        return get;
    }
    std::unique_ptr<Creature> giveBirth(const Creature& creature, Vector2 coordinates,float sizeRadius, float velocity , float seeingRadius){

        std::unique_ptr<Creature> child = makeChild(creature, coordinates,sizeRadius,velocity,seeingRadius);

        return child;
    }


    virtual ~entityFactory() = default;
};

#endif // EXAMPLE_ENTITYFACTORY_H
