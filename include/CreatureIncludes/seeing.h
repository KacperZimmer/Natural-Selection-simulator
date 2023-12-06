
#ifndef EXAMPLE_SEEING_H
#define EXAMPLE_SEEING_H
#include <raylib.h>



class Seeing {
private:
    Vector2 hightlightPositionVector{};
    bool shouldDisplayVectorDirection{false};
    bool shouldDisplayVisionRange{false};
    float seeingRange{20.f};
public:
    Seeing(const Vector2& posToDrawIn){
        this->hightlightPositionVector = posToDrawIn;
    }

    void setHightlightPositionVector(const Vector2 &hightlightPositionVector);

    bool isShouldDisplayVectorDirection() const;

    bool isShouldDisplayVisionRange() const;

    void highlightVisionRange();

    bool ShouldDisplayVisionRange() const;
    bool ShouldDisplayVectorDirection() const;

    void setShouldDisplayVectorDirection(bool shouldDisplayVectorDirection);
    void setShouldDisplayVisionRange(bool shouldDisplayVisionRange);
};


#endif //EXAMPLE_SEEING_H
