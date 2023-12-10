
#include "../../include/CreatureIncludes/foodInclude/foodContainer.h"

void FoodContainer::generateFood(int quantity) {
    for(int i = 0; i < quantity; ++i){
        this->foodVector.emplace_back(std::make_unique<Food>(10));
    }
}

const std::vector<std::unique_ptr<Food>> &FoodContainer::getFoodArray() const{
    return this->foodVector;
}

void FoodContainer::renderContainer() {
    for(const auto& i : this->foodVector){
        i->render();
    }
}
