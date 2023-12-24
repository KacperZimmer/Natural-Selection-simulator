#include "../../../include/CreatureIncludes/creatureContainer/CreatureContainer.h"
#include "../../../include/EntityFactoryInclude/creatureFactory.h"

void CreatureContainer::render() {

    for(const auto& creature : this->creatureContainer){
        if(creature == nullptr){
            continue;
        }

        creature->render();
    }
}

void CreatureContainer::update(FoodContainer& foodContainer) {

    for (size_t i = 0; i < this->creatureContainer.size(); ++i) {

        if(this->creatureContainer[i] == nullptr){
            continue;
        }

        if (creatureContainer[i]->isDead()) {

            deltatime = GetFrameTime();

            if (this->shouldUpdate <= this->timeToUpdate) {
                this->shouldUpdate += deltatime;

            } else {
                creatureContainer[i].reset();
                this->shouldUpdate = 0.f;
            }
        }else{
            creatureContainer[i]->update(foodContainer);

        }

    }


}

void CreatureContainer::generate(int quantity) {
    for(int i = 0; i < quantity; ++i){
        this->creatureContainer.push_back(this->factory->prepareOne(100,100,10.f, 2.f, 30.f));
    }
}

void CreatureContainer::updateVision() {
    for(auto& creature : this->creatureContainer){
        if(creature == nullptr){
            continue;
        }
        creature->turnOnVision();
    }
}

