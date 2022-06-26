#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Circle properties
    Vector2 circle_center = Vector2{300, 300};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            // DrawCircle(300, 300, 100, RED);
            // DrawCircleV(circle_center, 100, ORANGE);
            // DrawCircleGradient(circle_center.x, circle_center.y, 100, ORANGE, PINK);
            // DrawCircleLines(circle_center.x, circle_center.y , 100, BLACK);
            DrawCircleSector(circle_center, 100, 0, 270, 100, BLUE);
            DrawCircleSectorLines(circle_center, 100, 0, 270, 100, YELLOW);

        EndDrawing();
    }
    
}
