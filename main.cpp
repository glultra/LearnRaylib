#include <raylib.h>
#include <math.h>

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
        float time = GetTime();
        float xValue = std::sin(time);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawPoly(Vector2{300, 100}, 5, 100, 45 * xValue, LIME);
            DrawPolyLines(Vector2{300, 300}, 9, 50, 180 * xValue, PINK);
            DrawPolyLinesEx(Vector2{300, 450}, 9, 50, 270 * xValue, 7, GOLD);
        EndDrawing();
    }

    // De Initialize context of opengl.
    CloseWindow();
    
}
