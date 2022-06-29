#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Window Option.
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    // Texture 2D. 
    Texture2D texture = LoadTexture("./res/images/light.png");


    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        // Case 1: Responsive Staticilly depends to the image size.
        // SetWindowSize(texture.width, texture.height);
        // Case 2: Responsive By Window Size.
        texture.width = GetScreenWidth();
        texture.height = GetScreenHeight();

        // Check if Draggged/Dropped.
        if(IsFileDropped()){
            UnloadTexture(texture);
            FilePathList source = LoadDroppedFiles();
            if(source.count == 1){
                if(IsFileExtension(source.paths[0], ".png"))
                    texture = LoadTexture(source.paths[0]);
            }
            UnloadDroppedFiles(source);
        }

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    // Unload texture.
    UnloadTexture(texture);

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
