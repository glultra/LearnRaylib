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

    // Rectangle rect.
    Rectangle rect{250, 250, 100, 100};
    // Player rect.
    Rectangle player{20, 100, 100, 100};

    bool isCollided = false;

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        Vector2 mouse_pos = GetMousePosition();
        // player.x = mouse_pos.x - player.width / 2;
        // player.y = mouse_pos.y - player.height / 2;

        // Moving player.
        if(IsKeyDown(KEY_W))
            player.y -= 5.0f ;
        else if(IsKeyDown(KEY_S))
            player.y += 5.0f ;
        if(IsKeyDown(KEY_D))
            player.x += 5.0f ;
        else if(IsKeyDown(KEY_A))
            player.x -= 5.0f ;


        if(CheckCollisionRecs(player, rect)){
            isCollided = true;
        }else{
            isCollided = false;
        }

        // Collided Rectangle.
        Rectangle collidedRec = GetCollisionRec(player, rect);
        float area = collidedRec.height * collidedRec.width;
        std::string msg_box;

        // Collision With Window.
        // 1-Detecting Collision from left side.
        if(player.x < 0){
            player.x = 0;
        }
        // 2- Detecting Collision from right side.
        else if(player.x + player.width > SCREEN_WIDHT){
            player.x = SCREEN_WIDHT - player.width;
        }

        // 3-Detecting Collision from top side.
        if(player.y < 0){
            player.y = 0;
        }
        // 4- Detecting Collision from bottom side.
        else if(player.y + player.height > SCREEN_HEIGHT){
            player.y = SCREEN_HEIGHT - player.height;
        }


        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawRectangleRec(rect, RED);
            DrawRectangleRec(player, BLUE);
            DrawRectangleRec(collidedRec, YELLOW);
            msg_box.append("Width :");
            msg_box.append(std::to_string(collidedRec.width));
            DrawText(msg_box.c_str(), 10, 10, 30, BLACK);
            msg_box.clear();
            msg_box.append("height :");
            msg_box.append(std::to_string(collidedRec.height));
            DrawText(msg_box.c_str(), 10, 60, 30, BLACK);
            msg_box.clear();
            msg_box.append("Area :");
            msg_box.append(std::to_string(area));
            DrawText(msg_box.c_str(), 10, 110, 30, BLACK);

            if(isCollided)
                DrawText("Colided", player.x, player.y - 100, 30, GREEN);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
