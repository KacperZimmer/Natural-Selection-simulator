
#ifndef EXAMPLE_SEEING_H
#define EXAMPLE_SEEING_H
#include <raylib.h>
#include <vector>
#include "foodInclude/Food.h"
#include <memory>

class Seeing {
private:
    Vector2 hightlightPositionVector{};
    bool shouldDisplayVisionRange{false};
    float seeingRange{20.f};
public:
    Seeing(const Vector2& posToDrawIn){
        this->hightlightPositionVector = posToDrawIn;
    }
    int isFoodInRange(const std::vector<std::unique_ptr<Food>>& foodVector) const;

    void setHightlightPositionVector(const Vector2 &hightlightPositionVector);
    void setShouldDisplayVisionRange(bool shouldDisplayVisionRange);

    void highlightVisionRange();
    bool ShouldDisplayVisionRange() const;

};


#endif //EXAMPLE_SEEING_H
