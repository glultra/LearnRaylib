#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Line properties.
    Vector2 start_pos = Vector2{100, 100};
    Vector2 end_pos = Vector2{200, 100};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            // DrawLine(100, 100, 200, 200, RED);
            // DrawLineV(Vector2{100, 100}, Vector2{200, 200}, BLACK);
            // DrawLineEx(start_pos, end_pos, 10, BLACK);
            // DrawLineBezier(start_pos, end_pos, 5, GREEN);
            // DrawLineBezier(Vector2{200, 200}, Vector2{300, 100}, 5, PURPLE);
            // DrawLineBezierCubic(start_pos, end_pos, GetMousePosition(), GetMousePosition(), 3, ORANGE);
            DrawLineBezierQuad(start_pos, end_pos, GetMousePosition(), 3, GREEN);
        EndDrawing();
    }
    
}
