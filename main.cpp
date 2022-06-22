#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Rectangle position.
    Vector2 rect_pos{100.0f, 100.0f};

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        static Color color = ORANGE;
        Vector2 mouse_pos = GetMousePosition();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            color = GREEN;
        else if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            color = ORANGE;

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawLineBezier(Vector2{0, 0}, mouse_pos, 4, color);
            DrawRectangleV(Vector2{mouse_pos.x - 50, mouse_pos.y - 50}, Vector2{100, 100}, color);
            DrawCircleV(mouse_pos, 30, WHITE);

        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
