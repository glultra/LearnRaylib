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

    // Snake pixels.
    std::vector<Vector2> snake_points;
    Vector2 snake_point = Vector2{SCREEN_WIDHT / 2.0f, SCREEN_HEIGHT / 2.0f};

    // Camera2D.
    Camera2D camera{0};
    camera.zoom = 1.0f;
    camera.offset = Vector2{SCREEN_WIDHT/2.0f, SCREEN_HEIGHT/2.0f};
    camera.target = snake_point;
    camera.rotation = 0.0f;

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // Check if snake's length.
        if(snake_points.size() > 150)
            snake_points.erase(snake_points.begin());

        // Update Camera
        camera.target = snake_point;
        camera.zoom += GetMouseWheelMove() * 0.05f;

        // Action Movemenet.
        if(IsKeyDown(KEY_W))
            snake_point.y -= 1.0f;
        if(IsKeyDown(KEY_D))
            snake_point.x += 1.0f;
        if(IsKeyDown(KEY_S))
            snake_point.y += 1.0f;
        if(IsKeyDown(KEY_A))
            snake_point.x -= 1.0f;

        if(IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W) || IsKeyDown(KEY_S))
        snake_points.push_back(snake_point);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            BeginMode2D(camera);
            for (auto snake_p : snake_points)
            {
                DrawCircleV(snake_p, 5, Fade(SKYBLUE, 0.9f));
            }
                DrawCircleV(snake_point, 5, Fade(BLUE, 0.9f));
            EndMode2D();
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
