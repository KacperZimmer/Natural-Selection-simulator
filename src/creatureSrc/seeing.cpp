
#include "../../include/CreatureIncludes/seeing.h"

#include <iostream>
void Seeing::highlightVisionRange() {

    if(this->shouldDisplayVisionRange){
        DrawCircle(this->hightlightPositionVector.x, this->hightlightPositionVector.y, 30.f, Color{25, 102, 209,125});
    }
}

void Seeing::setShouldDisplayVisionRange(bool shouldDisplayVisionRang) {
    this->shouldDisplayVisionRange = shouldDisplayVisionRang;
}

void Seeing::setHightlightPositionVector(const Vector2 &hightlightPositionVector) {
    this->hightlightPositionVector = hightlightPositionVector;
}

bool Seeing::ShouldDisplayVisionRange() const {
    return this->shouldDisplayVisionRange;
}
