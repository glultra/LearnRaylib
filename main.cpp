#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <vector>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Pixels.
    std::vector<Vector2> pixels;
    Vector2 pixel = Vector2{300, 300};

    // Target FPS.
    // SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        static int interval = 0;
        static int currentDir = 0;
        const float step = 0.45f;
        interval++;
        if(interval % 5 == 0){
            currentDir = GetRandomValue(0, 4);
        }

        switch (currentDir)
        {
        case 0:
            // Go for Right.
            pixel.x += step;
            break;
        case 1:
            // Go for Up.
            pixel.y -= step;
            break;
        case 2:
            // Go for left.
            pixel.x -= step;
            break;
        case 3:
            // Go for down.
            pixel.y += step;
            break;
        }

        pixels.push_back(pixel);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            // DrawPixel(pixel.x, pixel.y, RED);
            // DrawRectangleV(pixel, Vector2{30, 30}, RED);
            for (auto pix : pixels)
            {
                DrawPixel(pix.x, pix.y, RED);
                // DrawRectangleV(pix, Vector2{30, 30}, RED); 
            }
            
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
