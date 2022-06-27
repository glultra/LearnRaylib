#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle Properties.
    Vector2 rec_pos = Vector2{100, 80};
    Vector2 rec_size = Vector2{200, 100};

    // Rectangle object.
    Rectangle rec = Rectangle{400, 100, 100, 200};
    

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{23, 21, 21});
            // <--- DRAW --->
            DrawRectangle(250, 250, 100, 100, ORANGE);
            DrawRectangleV(rec_pos, rec_size, BLUE);
            rec.x = 200;
            DrawRectangleRec(rec, GREEN);
            // DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, PURPLE);
            DrawRectangleLinesEx(rec, 15, SKYBLUE);
            rec.x = 120;
            DrawRectanglePro(rec, Vector2{rec.width / 2, rec.height / 2}, 45, GOLD);
            rec.x = 450;
            rec.y = 50;
            DrawRectangleGradientV(rec.x, rec.y, rec.width, rec.height, RED, SKYBLUE);
            // DrawRectangleGradientH(rec.x, rec.y, rec.width, rec.height, RED, SKYBLUE);
            rec.y = 350;
            DrawRectangleGradientEx(rec, PINK, SKYBLUE, RED, GOLD);
        EndDrawing();
    }
    
    // De-Initialize OpenGL Context.
    CloseWindow();
}
