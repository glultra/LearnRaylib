#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include "src/gui_tile_buttons.hpp"

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Texture2D obj;
    Texture2D light = LoadTexture("./res/images/light.png");
    Color color_state = WHITE;

    // GUI Tile Buttons.
    GuiTileButtons tileButton = GuiTileButtons();

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        tileButton.CheckCollision(color_state);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawTexture(light, 170, 10, color_state);
            tileButton.Draw();
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
