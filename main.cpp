#include <raylib.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Texture 2D.
    Texture2D pink_panther = LoadTexture("./res/images/pink-panther.png");

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        // Toggle button (NO GUI yet).
        static bool isTurnedOn = false;
        if(IsKeyPressed(KEY_SPACE)){
            // if true return false.
            // else if false return true.
            isTurnedOn = isTurnedOn ? false : true; // if is true returns first case else returns second case.
        }

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawTexture(pink_panther, 10, 10, isTurnedOn ? WHITE : BROWN);
        EndDrawing();
    }
    
}
