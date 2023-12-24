#include <iostream>
#include "include/CreatureIncludes/creature.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"
#include "include/foodInclude/Food.h"
#include "include/foodInclude/foodContainer.h"
#include "include/EntityFactoryInclude/entityFactory.h"
#include "include/EntityFactoryInclude/creatureFactory.h"
#include "include/CreatureIncludes/creatureContainer/CreatureContainer.h"

int main() {



    FoodContainer foodContainer{};
    foodContainer.generateFood(70);

    std::unique_ptr<entityFactory> entityFactorytest = std::make_unique<CreatureFactory>();

    CreatureContainer creatureContainer{entityFactorytest};

    creatureContainer.generate(30);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Selection simulator");

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        creatureContainer.render();
        creatureContainer.update(foodContainer);

        if(GuiButton(Rectangle{0.f, SCREEN_HEIGHT - 50,120,50},"Highlight Vision")){

            creatureContainer.updateVision();

        }

        foodContainer.renderContainer();

        EndDrawing();
    }

    return 0;
}
