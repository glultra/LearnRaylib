#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Enable MSAA 4X.
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Initialize Audio Device.
    InitAudioDevice();

    // Music object.
    Music music = LoadMusicStream("./res/music/wisdom.mp3");

    PlayMusicStream(music);


    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        
        // Update Music Buffer.
        UpdateMusicStream(music);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->

        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
