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
    Tilemap tileblock(50, 2, 2);

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            
            // <--- DRAW --->
            tileblock.Draw();

        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
