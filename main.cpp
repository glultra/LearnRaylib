#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle rect.
    Rectangle rect{250, 250, 100, 100};
    // Player rect.
    Rectangle player{20, 100, 100, 100};

    bool isCollided = false;

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        Vector2 mouse_pos = GetMousePosition();
        player.x = mouse_pos.x - player.width / 2;
        player.y = mouse_pos.y - player.height / 2;

        if(CheckCollisionRecs(player, rect)){
            isCollided = true;
        }else{
            isCollided = false;
        }

        
        

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawRectangleRec(rect, RED);
            DrawRectangleRec(player, BLUE);
            if(isCollided)
                DrawText("Colided", player.x, player.y - 100, 30, GREEN);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
