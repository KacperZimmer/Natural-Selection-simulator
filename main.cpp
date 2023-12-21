#include <iostream>
#include "include/CreatureIncludes/creature.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"
#include "include/CreatureIncludes/foodInclude/Food.h"
#include "include/CreatureIncludes/foodInclude/foodContainer.h"
#include "include/EntityFactoryInclude/entityFactory.h"
#include "include/EntityFactoryInclude/creatureFactory.h"

int main() {


    std::vector<std::unique_ptr<Creature>> creatureContainer{};

    FoodContainer foodContainer{};
    foodContainer.generateFood(3000);

    std::unique_ptr<entityFactory> entityFactorytest = std::make_unique<CreatureFactory>();


    creatureContainer.push_back(entityFactorytest->prepareOne(SCREEN_HEIGHT / 2,SCREEN_WIDTH / 2, 10, 2,30));


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Selection simulator");

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
//
        creatureContainer[0]->render();

        creatureContainer[0]->update(foodContainer);

//        if(GuiButton(Rectangle{0.f, SCREEN_HEIGHT - 50,120,50},"Highlight Vision")){
//            creature.turnOnVision();
//            creature1.turnOnVision();
//        }
//

        foodContainer.renderContainer();

        EndDrawing();
    }

    return 0;
}
