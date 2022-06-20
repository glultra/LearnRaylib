#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle attributes
    Vector2 rec_pos = Vector2{300, 150};
    Vector2 rec_size = Vector2{100, 100};
    Vector2 rec_origin = Vector2{50, 50};

    Rectangle rect = Rectangle{rec_pos.x, rec_pos.y, rec_size.x ,rec_size.y};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            rect.y = 100;
            DrawRectangleGradientEx(rect, ORANGE, PURPLE, GREEN, PINK);
            DrawRectangleLines(rect.x, rect.y, rect.width, rect.height, BLACK);
            DrawRectangleLinesEx(rect, 3, BLACK);
            rect.y = 350;
            DrawRectanglePro(rect, rec_origin, 45, ORANGE);

            rect.y = 470;
            DrawRectangleRounded(rect, 100, 100, RED);
            DrawRectangleRoundedLines(rect, 100, 100, 5, BLACK);
            
        EndDrawing();
    }
    
}
