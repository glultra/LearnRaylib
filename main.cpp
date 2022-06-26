#include <raylib.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include "src/timer.h"
#include <iomanip>

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

        rect.x = 200 + (timer.xValue * 150 );
        rect.y = 200 + (timer.yValue * 150 );
        
        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawRectangleRec(rect, BLUE);
            time = round(time * 100) / 100;
            DrawText(std::to_string(time).substr(0,3).append(" s =  ").c_str(), 10, 10, 30, GREEN);
            DrawText(std::to_string(timer.frame_count).append(" FPS").c_str(), 120, 10, 30, PURPLE);
            DrawFPS(500, 10);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
