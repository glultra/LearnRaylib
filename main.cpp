#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Triangle Attributes.
    Vector2 vertex1 = Vector2{200, 200};
    Vector2 vertex2 = Vector2{300, 200}; 
    Vector2 vertex3 = Vector2{250, 100}; 

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawTriangle(vertex1, vertex2, vertex3, ORANGE);
        EndDrawing();
    }
    
}
