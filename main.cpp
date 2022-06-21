#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            // DrawLine(200, 200, 300, 300, RED);
            // DrawLineEx(Vector2{200, 200}, Vector2{300, 200}, 6, RED);
            // DrawLineBezier(Vector2{200, 200}, Vector2{300, 300}, 3, ORANGE);
            // DrawLineBezier(Vector2{300, 300}, Vector2{400, 200}, 3, GREEN);
            // DrawLineBezierCubic(Vector2{200, 200}, Vector2{400,200}, Vector2{250,300}, Vector2{350,100}, 3, BLUE);
            DrawLineBezierQuad(Vector2{200, 200}, Vector2{400, 200}, GetMousePosition(), 3, BROWN);
        EndDrawing();
    }
    
}
