#include <raylib.h>
#include <string.h>
#include <iostream>
#include "src/timer.h"

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle object.
    Rectangle rec{250, 250, 100, 100};

    // Timer object.
    Timer timer = Timer{};

    // Settarget fps.
    SetTargetFPS(60); 

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        timer.UpdateTime(time);
        
        rec.x = 250 + (timer.xValue * 100); 
        rec.y = 250 + (timer.yValue * 100); 
       
        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawRectangleRec(rec, BLUE);
            DrawText(std::to_string((int)time).c_str(), 10, 10, 30, BLUE);
            DrawText(std::to_string((int)timer.frame_count).c_str(), 100, 10, 30, BLUE);
            DrawFPS(500, 10);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
