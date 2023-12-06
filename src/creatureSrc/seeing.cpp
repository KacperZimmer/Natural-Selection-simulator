
#include "../../include/CreatureIncludes/seeing.h"

#include <iostream>
void Seeing::highlightVisionRange() {

    if(!this->shouldDisplayVisionRange){
        DrawCircle(this->hightlightPositionVector.x, this->hightlightPositionVector.y, 30.f, Color{25, 102, 209,125});
        std::cout << this->hightlightPositionVector.x << std::endl;
    }
}

bool Seeing::ShouldDisplayVectorDirection() const {
    return this->shouldDisplayVisionRange;
}

bool Seeing::ShouldDisplayVisionRange() const {
    return this->shouldDisplayVisionRange;
}

void Seeing::setShouldDisplayVectorDirection(bool shouldDisplayVectorDirection) {
    this->shouldDisplayVectorDirection = shouldDisplayVectorDirection;
}

void Seeing::setShouldDisplayVisionRange(bool shouldDisplayVisionRange) {
    this->shouldDisplayVisionRange = shouldDisplayVisionRange;
}

bool Seeing::isShouldDisplayVectorDirection() const {
    return shouldDisplayVectorDirection;
}

bool Seeing::isShouldDisplayVisionRange() const {
    return shouldDisplayVisionRange;
}

void Seeing::setHightlightPositionVector(const Vector2 &hightlightPositionVector) {
    this->hightlightPositionVector = hightlightPositionVector;
}
