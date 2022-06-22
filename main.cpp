#include <raylib.h>
#include <iostream>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle Object.
    Vector2 rect_pos = Vector2{250, 250};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        if(IsKeyDown(KEY_UP))
            rect_pos.y -= 1.0f;
        else if(IsKeyDown(KEY_DOWN))
            rect_pos.y += 1.0f;

        if(IsKeyDown(KEY_RIGHT))
            rect_pos.x += 1.0f;
        else if(IsKeyDown(KEY_LEFT))
            rect_pos.x -= 1.0f;

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawRectangleV(rect_pos, Vector2{100, 100}, RED);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
