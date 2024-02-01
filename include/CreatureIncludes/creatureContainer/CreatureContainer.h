
#ifndef EXAMPLE_CREATURECONTAINER_H
#define EXAMPLE_CREATURECONTAINER_H


#include <vector>
#include "../creature.h"
#include "../../EntityFactoryInclude/entityFactory.h"

class CreatureContainer {
private:
    std::vector<std::unique_ptr<Creature>> creatureContainer{};
    std::unique_ptr<entityFactory> factory;


public:
    void render();
    float startingXpos{20};
    float startingYpos{20};

    const float timeToUpdate{1.f};
    float shouldUpdate{};
    float deltatime;
    void update(FoodContainer& foodContainer);
    void generate(int quantity);
    void generateSymmetricaly(size_t quantity, float radius);
    CreatureContainer(std::unique_ptr<entityFactory>& factory){
        this->factory = std::move(factory);
    }
    void updateVision();

};


#endif //EXAMPLE_CREATURECONTAINER_H
