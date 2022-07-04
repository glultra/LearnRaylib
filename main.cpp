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

    // Camera 2D.
    Camera2D camera = Camera2D{0};
    camera.zoom = 1.0f;
    camera.offset = Vector2{SCREEN_WIDHT/2, SCREEN_HEIGHT/2};
    camera.rotation = 0;
    camera.target = pixel;

    // Target FPS.
    SetTargetFPS(120);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        static int interval = 0;
        static int currentDir = 0;
        const float step = 1.0f;
        interval++;
        if(interval % 15 == 0){
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

        // Update Camera
        camera.zoom += GetMouseWheelMove() * 0.05f;
        camera.target = pixel;
        camera.rotation = std::sin(GetTime()) * 45;

        if(camera.zoom < 0.3f)
            camera.zoom = 0.3f;

        pixels.push_back(pixel);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            // DrawPixel(pixel.x, pixel.y, RED);
            // DrawRectangleV(pixel, Vector2{30, 30}, RED);
            BeginMode2D(camera);
                for (auto pix : pixels)
                {
                    // DrawPixel(pix.x, pix.y, BLUE);
                    DrawRectangleV(pix, Vector2{5, 5}, BLUE); 
                }
            EndMode2D();
            
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
