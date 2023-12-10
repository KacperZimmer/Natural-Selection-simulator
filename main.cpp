#include <iostream>
#include "include/CreatureIncludes/creature.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"
#include "include/CreatureIncludes/foodInclude/Food.h"
#include "include/CreatureIncludes/foodInclude/foodContainer.h"
int main() {
    // TODO clean up the mess here when finished with most of logic

    Creature creature{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10};

    FoodContainer foodContainer{};
    foodContainer.generateFood(5);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Selection simulator");

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        if(GuiButton(Rectangle{0.f, SCREEN_HEIGHT - 50,120,50},"Highlight Vision")){
            creature.turnOnVision();
        }

        creature.render();
        creature.update(foodContainer);
        foodContainer.renderContainer();

        EndDrawing();
    }

    return 0;
}
