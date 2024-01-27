#include "../../../include/CreatureIncludes/creatureContainer/CreatureContainer.h"
#include "../../../include/EntityFactoryInclude/creatureFactory.h"
#include <iostream>

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

void CreatureContainer::generateSymmetricaly(size_t quantity,float size) {
    int scale = size / 10;

    size_t numEachSide = quantity / 4;
    //TODO this looks absolutely disgusting
    float y_spacing = (SCREEN_HEIGHT / ((size) * 2 * static_cast<float> (quantity))) * static_cast<float>((75 * ((scale == 0) ? 1 : scale)));
    float x_spacing = (SCREEN_WIDTH / ((size) * 2 *  static_cast<float> (quantity))) * static_cast<float>((75 * ((scale == 0) ? 1 : scale)));
        std::cout << y_spacing << std::endl;

        std::cout << numEachSide << "this is the number" << std::endl;

        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < numEachSide; ++j) {

                std::unique_ptr<Creature> currentCreature = std::move(factory->prepareOne(this->startingXpos, this->startingYpos, size, 2.f, 20.f));
                creatureContainer.push_back(std::move(currentCreature));

                switch (i){
                    case 0:
                        this->startingYpos += y_spacing;
                        break;

                    case 1:
                        this->startingXpos += x_spacing;
                        break;

                    case 2:
                        this->startingYpos -= y_spacing;
                        break;

                    case 3:
                        this->startingXpos -= x_spacing;
                        break;

                    default:
                        std::cout << "wrong indexing" << std::endl;
                }
            }
        }




}

