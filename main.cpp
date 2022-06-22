#include <raylib.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Texture 2D.
    Texture2D pink_panther = LoadTexture("./res/images/pink-panther.png");
    pink_panther.height = 300;
    pink_panther.width = 150;

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        // Toggle button (NO GUI yet).
        static bool isTurnedOn = false;
        float time = GetTime();
        float xValue = std::sin(time); // -1.0 to +1.0
        std::cout << xValue << std::endl;

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
            // DrawTexture(pink_panther, 10, 10, isTurnedOn ? WHITE : BROWN);
            // DrawTextureEx(pink_panther, Vector2{10, 10}, 45, 1.0, WHITE);
            // DrawTextureRec(pink_panther, Rectangle{40, 0, 100, 100},Vector2{10, 10}, WHITE );
            DrawTextureTiled(pink_panther, Rectangle{40, 0, 100, 100}, Rectangle{0, 0, 600, 600}, Vector2{10, 10}, 360 * xValue, 1, WHITE);
            // DrawTextureQuad(pink_panther, Vector2{5, 5}, Vector2{5, 5}, Rectangle{0, 0, 600, 600}, WHITE);
        EndDrawing();
    }
    
}
