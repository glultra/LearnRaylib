#include <raylib.h>
#include <cmath>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle object.
    Rectangle rec{225, 150, 150, 300};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        float xValuePos = std::sin(time) / 2.0f + 0.5f;
        float yValuePos = std::cos(time) / 2.0f + 0.5f;

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{23, 21, 21});
            // <--- DRAW --->
           DrawRectangleGradientEx(
                rec,
                Fade(RED, xValuePos),
                Fade(PINK, yValuePos),
                Fade(SKYBLUE, yValuePos),
                Fade(ORANGE, xValuePos)
           );
        EndDrawing();
    }
    
    // De-Initialize OpenGL Context.
    CloseWindow();
}
