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
    Rectangle rec{250, 250, 100, 100};

    // Settarget fps.
    SetTargetFPS(60); 

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        float xValue = std::sin(time);
        float xValuePos = std::sin(time) / 2.0f + 0.5f;

        static int frame_count = 0;
        frame_count++;


        rec.x = 100 + (xValuePos * 300); 
        
        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawRectangleRec(rec, BLUE);
            DrawText(std::to_string((int)time).c_str(), 10, 10, 30, BLUE);
            DrawText(std::to_string((int)frame_count).c_str(), 100, 10, 30, BLUE);
            DrawFPS(500, 10);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
