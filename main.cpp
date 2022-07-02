#include <raylib.h>
#include <math.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // MSAA 4X FLAG
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float time = GetTime();
        float xValue = std::sin(time) / 2.0f + 0.5f;

        Color blue = BLUE;
        Color skyblue = SKYBLUE;
        Color darkblue = DARKBLUE;

        blue.g *= xValue;
        blue.b *= xValue;

        skyblue.g *= xValue;
        skyblue.b *= xValue;

        darkblue.b *= xValue;
        darkblue.g *= xValue;

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            // ClearBackground(Color{13,17,23,255});
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawPoly(Vector2{300, 300}, 7, 120, 45 * xValue, darkblue);
            DrawPolyLinesEx(Vector2{300, 300}, 7, 100, 45 * xValue, 27, blue);
            DrawPolyLinesEx(Vector2{300, 300}, 7, 80, 90 * xValue, 27, skyblue);
            DrawPolyLinesEx(Vector2{300, 300}, 7, 60, 180 * xValue, 27, blue);
            DrawPolyLinesEx(Vector2{300, 300}, 7, 40, 300 * xValue, 27, skyblue);
            DrawPolyLinesEx(Vector2{300, 300}, 7, 20, 270 * xValue, 27, blue);
        EndDrawing();
    }
    
}
