#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Loafding Texture 2D.
    Texture2D pink_panther = LoadTexture("./res/images/pink-panther.png");

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        // Make a toggle.
        static bool isTurnedOn = false;

        if(IsKeyPressed(KEY_SPACE)){
            isTurnedOn = isTurnedOn ? false : true; // i want to reverse the button -> if true make it false  if false make it true.
        }

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawTexture(pink_panther, 50, 50, isTurnedOn ?  WHITE : BROWN);
        EndDrawing();
    }

    // De-Initialize OpenGL Context
    CloseWindow();
}
