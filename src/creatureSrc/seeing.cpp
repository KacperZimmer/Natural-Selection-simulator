
#include "../../include/CreatureIncludes/seeing.h"

#include <iostream>
#include "raymath.h"
void Seeing::highlightVisionRange() {

    if(this->shouldDisplayVisionRange){
        DrawCircle(this->hightlightPositionVector.x, this->hightlightPositionVector.y, 30.f, Color{25, 102, 209,125});
    }
}

void Seeing::setShouldDisplayVisionRange(bool shouldDisplayVisionRang) {
    this->shouldDisplayVisionRange = shouldDisplayVisionRang;
}

void Seeing::setHightlightPositionVector(const Vector2& hightlightPositionVector) {
    this->hightlightPositionVector = hightlightPositionVector;
}

bool Seeing::ShouldDisplayVisionRange() const {
    return this->shouldDisplayVisionRange;
}

int Seeing::isFoodInRange(std::vector<std::unique_ptr<Food>> &foodVector) {

    for( int i = 0; i < foodVector.size(); ++i){

        if(foodVector[i] && Vector2Distance(foodVector[i]->getPosition(), this->hightlightPositionVector) <= 0 + this->seeingRange + foodVector[i]->getFoodRadius() * 2){
            return i;

        }


    }
    return -1;
}

