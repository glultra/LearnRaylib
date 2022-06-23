#include <raylib.h>
#include <string.h>
#include <iostream>
#include <cmath>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle object.
    Rectangle rect = Rectangle{250, 250, 100, 100};

    // Settarget fps.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        float xValue = std::sin(time); // from -1.0 to +1.0
        float xValuePos = (xValue / 2.0) + 0.5; // from 0.0 to 1.0

        rect.x = 550 * xValuePos;
        
        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawRectangleRec(rect, RED);
            DrawText(std::to_string(xValuePos).c_str(), 10, 10, 30, GREEN);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
