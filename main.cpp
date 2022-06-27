#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Triangle Vertecies.
    Vector2 v1 = Vector2{200, 200};
    Vector2 v2 = Vector2{400, 200};
    Vector2 v3 = Vector2{300, 400};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawTriangle(v2, v1, v3, BLUE);
            DrawTriangleLines(v1, v2, v3, RED);
        EndDrawing();
    }
    
}
