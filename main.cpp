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

    // Circle Objects.
    Vector2 circle_center = Vector2{300, 300};
    Vector2 player_center = Vector2{ 50, 50};

    bool isCollided = false;

    float dx = 0.0f, dy = 0.0f, angle = 0.0f;
    float dxx = 0.0f, dyy = 0.0f;

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        player_center = GetMousePosition();

        isCollided = CheckCollisionPointCircle(player_center, circle_center, 100 - 40);

        if(!isCollided){
            // Find differences.
            dx = player_center.x - circle_center.x;
            dy = player_center.y - circle_center.y;

            // Find angle.
            angle = atan2f(dy, dx);

            // Radius1 + Radius2
            dxx = (100 - 40) * cosf(angle);
            dyy = (100 - 40) * sinf(angle);

            // Sum with player position.
            player_center.x = circle_center.x + dxx;
            player_center.y = circle_center.y + dyy;
        }

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawCircleV(circle_center, 100, WHITE);
            DrawCircleV(player_center, 40, BLUE);
            DrawCircleV(player_center, 15, BLACK);

        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
