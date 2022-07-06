#include <raylib.h>
#include <cmath>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle object.
    Rectangle rec = Rectangle{200 , 100, 200, 400};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{23, 21, 21});
            // <--- DRAW --->
            DrawRectangleGradientEx(rec, Fade(PINK, std::sin(GetTime())/2.0f + 0.5f), Fade(SKYBLUE, std::sin(GetTime())/2.0f + 0.5f), Fade(RED, std::cos(GetTime())/2.0f + 0.5f), Fade(GOLD, std::cos(GetTime())/2.0f + 0.5f));
        EndDrawing();
    }
    
    // De-Initialize OpenGL Context.
    CloseWindow();
}
