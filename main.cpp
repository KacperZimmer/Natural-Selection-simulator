#include <iostream>
#include "include/CreatureIncludes/creature.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"
#include "include/CreatureIncludes/foodInclude/Food.h"
#include "include/CreatureIncludes/foodInclude/foodContainer.h"
#include "include/EntityFactoryInclude/entityFactory.h"
#include "include/EntityFactoryInclude/creatureFactory.h"

int main() {
    // TODO clean up the mess here when finished with most of logic

    Creature creature{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10};

    Creature creature1{SCREEN_WIDTH / 2, 100, 10};

    std::vector<std::unique_ptr<Creature>> creatureContainer{};

    FoodContainer foodContainer{};
    foodContainer.generateFood(300);

    std::unique_ptr<entityFactory> entityFactorytest = std::make_unique<CreatureFactory>();


    creatureContainer.push_back(entityFactorytest->prepareOne());


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Selection simulator");

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        creatureContainer[0]->render();

//        if(GuiButton(Rectangle{0.f, SCREEN_HEIGHT - 50,120,50},"Highlight Vision")){
//            creature.turnOnVision();
//            creature1.turnOnVision();
//        }
//
//        creature.render();
//
//        creature1.render();
//        creature.update(foodContainer);
//        creature1.update(foodContainer);
//
//        foodContainer.renderContainer();

        EndDrawing();
    }

    return 0;
}
