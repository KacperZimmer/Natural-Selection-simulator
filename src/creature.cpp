#include <random>
#include <iostream>
#include "../include/creature.h"
#include "../include/constantValues.h"


void Creature::render(bool highlightVision) {
    movement.move();
    DrawCircle(movement.getPosition().x, movement.getPosition().y,20, BLUE);
}





//void Creature::visualizeSeeing(bool shouldRender) {
//    if(shouldRender) {
//        DrawLine(this->creaturePosVector.x, this->creaturePosVector.y, creaturePosVector.x + 20 * xDirection,
//                 creaturePosVector.y + 30 * yDirection, Color{255, 0, 0, 255});
//        DrawCircle(this->creaturePosVector.x, this->creaturePosVector.y, 40.f, Color{116, 45, 255, 128});
//    }
//}

//void Creature::manageLifeCycle(bool renderSeeing) {
//
//    /*
//     * function takes care of proper rendering parts of the creatures
//     * and takes care of behaviour such as detecting food, going to certain target
//     */
//
//    DrawCircle(static_cast<int>(this->creaturePosVector.x),static_cast<int>(this->creaturePosVector.y), this->radiusCreature, BLUE);
//    move(a);
//    visualizeSeeing(renderSeeing);
//}
