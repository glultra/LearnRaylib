#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include "src/tilemap.h"

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Tilemap object.
    Tilemap tileblock{Vector2{50, 50}, Vector2{2, 2}};

    // Player
    Rectangle player{200, 200, 50, 50};

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // Player movements.
        if(IsKeyDown(KEY_A))
            player.x -= 5.0f;
        if(IsKeyDown(KEY_D))
            player.x += 5.0f;
        if(IsKeyDown(KEY_S))
            player.y += 5.0f;
        if(IsKeyDown(KEY_W))
            player.y -= 5.0f;

        // Checking collision for the tilemap.
        tileblock.CheckCollision(player);


        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            
            // <--- DRAW --->
            tileblock.Draw(ORANGE);
            DrawRectangleRec(player, BLUE);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
