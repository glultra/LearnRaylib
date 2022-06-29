#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Set Anti Aliasing Flags.
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_INTERLACED_HINT);
    SetConfigFlags(FLAG_VSYNC_HINT);

    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Image object.
    Image icon_img = LoadImage("./res/icons/koo.png"); 

    // Window Options
    // SetWindowSize(300, 300);
    SetWindowIcon(icon_img);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowState(FLAG_WINDOW_MAXIMIZED);
    SetWindowState(FLAG_FULLSCREEN_MODE);
    

    // Camera 2D.
    Camera2D camera{0};
    camera.offset = Vector2{300, 300};
    camera.rotation = 0;
    camera.zoom = 1.0f;
    camera.target = Vector2{300, 300};

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        SetWindowTitle(std::to_string(GetFPS()).append(" FPS").c_str());

        // Update Camera
        camera.zoom += GetMouseWheelMove() * 0.05f;

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            BeginMode2D(camera);
                DrawPoly(Vector2{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, 100, 50, 0, BLUE);
                DrawLineBezier(Vector2{0,0}, GetMousePosition(), 7, RED);
            EndMode2D();
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
