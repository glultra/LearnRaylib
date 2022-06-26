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
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            // DrawPoly(Vector2{300, 300}, 7, 50, 45, ORANGE);
            // DrawPolyLines(Vector2{300, 300}, 7, 50, 45, BLACK);
             DrawPolyLinesEx(Vector2{300, 300}, 7, 50, 45, 10, BLUE);
             DrawEllipse(200, 200, 50, 70, BLUE);
            DrawRing(Vector2{300, 430}, 70, 40, 0, 360, 50, BLUE);
        EndDrawing();
    }
    
}
