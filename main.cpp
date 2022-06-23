#include <raylib.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include "src/timer.h"

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle object.
    Rectangle rect = Rectangle{250, 250, 100, 100};

    // Timer object.
    Timer timer;
    
    // Settarget fps.
    SetTargetFPS(60); // 60 picture per second -> 1s = 60frame

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        timer.UpdateTime(time);

        rect.x = 200 + (timer.xValue * 200 );
        rect.y = 200 + (timer.yValue * 200 );
        
        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawRectangleRec(rect, RED);
            DrawText(std::to_string(time).c_str(), 10, 10, 30, GREEN);
            DrawText("=", 150, 10, 30, GREEN);
            DrawText(std::to_string(timer.frame_count).c_str(), 200, 10, 30, RED);
            DrawFPS(500, 10);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
