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

    // Movements
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    
    float velocity = 200.5f; // For moving the player.
    float speed = 2.0f; // For auto movements.


    // Settarget fps.
    SetTargetFPS(60); 

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        float xValue = std::cos(time * speed);
        float yValue = std::sin(time * speed);
        float xValuePos = std::sin(time * speed) / 2.0f + 0.5f;

        static int frame_count = 0;
        frame_count++;

        deltaTime = time - lastFrame;
        lastFrame = time;

        rec.x = 250 + (xValue * 100); 
        rec.y = 250 + (yValue * 100); 
       
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
