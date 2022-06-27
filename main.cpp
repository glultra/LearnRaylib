#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle object.
    Rectangle rec = Rectangle{100, 80, 200, 80};

    // Circle attribute.
    Vector2 center_pos = Vector2{300, 300};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            // DrawCircleV(center_pos, 50, GOLD);
            // DrawCircleLines(center_pos.x, center_pos.y, 50, BLUE);
            // DrawCircleGradient(center_pos.x, center_pos.y, 100, SKYBLUE, BLACK);
            DrawCircleSector(center_pos, 100, 0, 270, 100, MAROON);
            DrawCircleSectorLines(center_pos, 100, 0, 270, 100, GOLD);
            // DrawEllipse(center_pos.x, center_pos.y, 100, 50, Color{100, 120, 255, 255});
            // DrawEllipseLines(center_pos.x, center_pos.y, 100, 50, Color{100, 120, 255, 255});
            DrawRectangleRounded(rec, 0.9f, 100, GOLD);
            DrawRectangleRoundedLines(rec, 0.9f, 100, 7,  BLUE);

        EndDrawing();
    }
    
}
