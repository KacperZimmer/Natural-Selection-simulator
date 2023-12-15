
#include "../../include/CreatureIncludes/foodInclude/foodContainer.h"

void FoodContainer::generateFood(int quantity) {
    for(int i = 0; i < quantity; ++i){
        this->foodVector.emplace_back(std::make_unique<Food>(10));
    }
}

std::vector<std::unique_ptr<Food>> &FoodContainer::getFoodArray(){
    return this->foodVector;
}

void FoodContainer::renderContainer() {
    for(const auto& food : this->foodVector){

        if(food != nullptr){food->render();}
    }
}

void FoodContainer::deleteFood(int x) {

    std::unique_ptr<Food>& foodToDelete = this->foodVector[x];
    if(foodToDelete != nullptr){foodToDelete.reset();}
}

const Vector2 &FoodContainer::getVectorAtIndex(int index) {
    return this->foodVector[index]->getPosition();
}


