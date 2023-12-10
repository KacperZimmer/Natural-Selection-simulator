#ifndef EXAMPLE_FOODCONTAINER_H
#define EXAMPLE_FOODCONTAINER_H
#include <vector>
#include "../Food.h"
#include <memory>
class FoodContainer {
private:
    std::vector<std::shared_ptr<Food>> foodVector{};

public:
    void generateFood(int quantity);
    const std::vector<std::shared_ptr<Food>>& getFoodArray() const;
    void renderContainer();
};


#endif //EXAMPLE_FOODCONTAINER_H
