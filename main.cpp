#include <iostream>
#include "raylib.h"
#include "include/constantValues.h"
#include "include/CreatureIncludes/creature.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"



int main() {


    std::vector<Creature> creaturtable{};

    creaturtable.reserve(5);
for(int i = 0; i < 5; ++i){
        creaturtable.emplace_back(SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2, 10);
    }

Creature creature{SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2, 10};

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Selection simulator");

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        GuiLoadStyleDefault();

        if(GuiButton(Rectangle{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,100,100},"wizja")){
            creature.turnOnVision();
        }
        for(int i = 0; i < 5; i++){
            creaturtable[i].render(true);
        }

        EndDrawing();
    }

    return 0;
}
