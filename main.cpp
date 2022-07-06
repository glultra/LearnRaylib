#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle property.
    Rectangle rec = Rectangle{ 250, 200, 100, 200};
    Rectangle rec2 = Rectangle{ 100, 200, 100, 200};
    Rectangle rec3 = Rectangle{ 400, 200, 100, 200};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{23, 21, 21});
            // <--- DRAW --->
            // DrawRectangle(250, 250, 100, 100, ORANGE);
            // DrawRectangleV(rec_pos, rec_size, RED);
            // DrawRectangleRec(rec, GOLD);
            // DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, LIME);
            // DrawRectangleLinesEx(rec, 17, PINK);
            // DrawRectanglePro(rec, Vector2{10, 10}, 45.0f, BLUE);
            DrawRectangleGradientEx(rec, RED, PINK, ORANGE, BLUE);
            DrawRectangleGradientH(rec2.x, rec2.y, rec2.width, rec2.height, RED, SKYBLUE);
            DrawRectangleGradientV(rec3.x, rec3.y, rec3.width, rec3.height, RED, SKYBLUE);
        EndDrawing();
    }
    
    // De-Initialize OpenGL Context.
    CloseWindow();
}
