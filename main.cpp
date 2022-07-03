#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include "src/tilemap.h"

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Tilemap object.
    Tilemap tileblock{Vector2{50, 50}, Vector2{2, 2}};

    // Player
    Rectangle player{200, 200, 50, 50};

    // Camera 2D.
    Camera2D camera{0};
    camera.zoom = 1.0f; // Camera zoom
    camera.offset = Vector2{GetScreenWidth()/2.0f, GetScreenHeight() / 2.0f}; // Camera focus to the center of the screen.
    camera.target = Vector2{player.x , player.y}; // Camera follows the player.
    camera.rotation = 0.0f; 

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // Update camera.
        camera.target = Vector2{player.x , player.y}; // Camera follows the player.
        camera.rotation = 45.0f;
        camera.zoom += GetMouseWheelMove() * 0.05;
        if(camera.zoom < 0.3f )
            camera.zoom = 0.3f;

        // Player movements.
        if(IsKeyDown(KEY_A))
            player.x -= 5.0f;
        if(IsKeyDown(KEY_D))
            player.x += 5.0f;
        if(IsKeyDown(KEY_S))
            player.y += 5.0f;
        if(IsKeyDown(KEY_W))
            player.y -= 5.0f;

        // Checking collision for the tilemap.
        tileblock.CheckCollision(player);


        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            
            // <--- DRAW --->
            BeginMode2D(camera);
                tileblock.Draw(ORANGE);
                DrawRectangleRec(player, BLUE);
            EndMode2D();
            DrawText("positioned text", 0, 0, 30, BLUE);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
