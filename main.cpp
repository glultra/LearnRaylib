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

    // DeltaTime property
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // Settarget fps.
    SetTargetFPS(60); // 60 picture per second -> 1s = 60frame

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        float xValue = std::cos(time); // from +1.0 to -1.0
        float yValue = std::sin(time); // from -1.0 to +1.0
        float xValuePos = (xValue / 2.0) + 0.5; // from 1.0 to 0.0
        float yValuePos = (yValue / 2.0) + 0.5; // from 0.0 to 1.0

        deltaTime = time - lastFrame;
        lastFrame = time;

        static int frame_count = 0; 
        frame_count++;

        rect.x = 200 + (xValue * 200 );
        rect.y = 200 + (yValue * 200 );
        
        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawRectangleRec(rect, RED);
            DrawText(std::to_string(time).c_str(), 10, 10, 30, GREEN);
            DrawText("=", 150, 10, 30, GREEN);
            DrawText(std::to_string(frame_count).c_str(), 200, 10, 30, RED);
            DrawFPS(500, 10);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
