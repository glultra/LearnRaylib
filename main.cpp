#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);


    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawRectangle(150, 50, 100, 100, ORANGE);

        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
