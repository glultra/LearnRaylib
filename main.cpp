#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include "src/tilemap.h"
#include "src/timer.h"


#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Player Object.
    Rectangle player = {200, 200, 50, 50};

    // Tilemap object.
    Tilemap tileblock(Vector2{0, 0}, Vector2{2,2});

    // Camera2D object.
    Camera2D camera{0};
    camera.zoom = 1.0f;
    camera.target  = Vector2{player.x, player.y};
    camera.offset  = Vector2{GetScreenWidth()/2.0f, GetScreenHeight()/ 2.0f};
    camera.rotation = 0.0f;

    // Timer object.
    Timer timer;

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        // Update timers;
        timer.UpdateTime(time);

        if(IsKeyDown(KEY_W))
            player.y -= 5.0f;
        if(IsKeyDown(KEY_S))
            player.y += 5.0f;
        if(IsKeyDown(KEY_D))
            player.x += 5.0f;
        if(IsKeyDown(KEY_A))
            player.x -= 5.0f;

        // Check player Collision.
        tileblock.CheckCollision(player);

        // Update camera target.
        camera.target  = Vector2{player.x, player.y};

        // Update Tileblock offset.
        tileblock.SetOffset(Vector2{50 * timer.xValuePos, 2 });

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            BeginMode2D(camera);
                tileblock.Draw();
                DrawRectangleRec(player, DARKBLUE);
            EndMode2D();
            
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
