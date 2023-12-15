#ifndef EXAMPLE_FOODCONTAINER_H
#define EXAMPLE_FOODCONTAINER_H
#include <vector>
#include "Food.h"
#include <memory>
class FoodContainer {
private:
    std::vector<std::unique_ptr<Food>> foodVector{};

public:
    void generateFood(int quantity);
    std::vector<std::unique_ptr<Food>>& getFoodArray() ;
    void renderContainer();
    void deleteFood(int x);
};


#endif //EXAMPLE_FOODCONTAINER_H
