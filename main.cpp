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

    // Player Object.
    Rectangle player = {200, 200, 50, 50};

    // Tilemap object.
    Tilemap tileblock(50, 2, 2);

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        if(IsKeyDown(KEY_W))
            player.y -= 5.0f;
        if(IsKeyDown(KEY_S))
            player.y += 5.0f;
        if(IsKeyDown(KEY_D))
            player.x += 5.0f;
        if(IsKeyDown(KEY_A))
            player.x -= 5.0f;

        // Check player Collision.
        tileblock.CheckCollision(player);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            tileblock.Draw();
            DrawRectangleRec(player, DARKBLUE);

        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
