#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Font object.
    Font font = LoadFont("./res/fonts/Moby.ttf");
    Font font1 = LoadFont("./res/fonts/setback.png");

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawText("Hello World", 300, 300, 25, RED);
            DrawTextEx(font, "Hello world", Vector2{100, 50}, 45, 2, BLUE);
            DrawTextPro(font1, "Hello world", Vector2{70, 400}, Vector2{50, 50}, 45, 30, 5, PURPLE);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
