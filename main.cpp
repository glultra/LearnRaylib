#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <vector>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Tile blocks.
    std::vector<Rectangle> blocks;
    Rectangle player{200, 400, 50, 50};

    // Set each block's position.
    // for (int i = 0; i < 100; i++)
    // {
    //     Rectangle block;
    //     block.width  = 50;
    //     block.height = 50;
    //     block.x      = 50 + 52 * (i % 10);
    //     block.y      = 50 + 52 * (i / 10);
    //     blocks.push_back(block);
    // }


    for (int i = 0; i < 10; i++)
    {
        for (int j= 0; j < 10; j++)
        {
            if(i == 0 || i == 9 || j == 0 || j == 9){
                Rectangle block;
                block.width  = 50;
                block.height = 50;
                block.x      = 50 + 100 * i;
                block.y      = 50 + 52 * j;
                blocks.push_back(block);
            }
        }
    }
    
    

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
         // Moving player.
        if(IsKeyDown(KEY_W))
            player.y -= 5.0f ;
        else if(IsKeyDown(KEY_S))
            player.y += 5.0f ;
        if(IsKeyDown(KEY_D))
            player.x += 5.0f ;
        else if(IsKeyDown(KEY_A))
            player.x -= 5.0f ;

        for (auto block : blocks)
        {
            bool isCollided = CheckCollisionRecs(block, player);

             // Collided Rectangle.
            Rectangle collidedRec = GetCollisionRec(player, block);

            if(isCollided){
                // Checking for right side of the player and left side of the wall.
                if(player.x < block.x && player.x + player.width > block.x && collidedRec.height > 10){
                    player.x = block.x - player.width;
                }
                // Checking for bottom side of the player and top side of the wall.
                if(player.y < block.y && player.y + player.height > block.y && collidedRec.width > 10){
                    player.y = block.y - player.height;
                }
                // Checking for left side of the player and right side of the wall.
                if(player.x > block.x && player.x < block.x + block.width && collidedRec.height > 10){
                    player.x = block.x + player.width;
                }
                // Checking for top side of the player and bottom side of the wall.
                if(player.y > block.y && player.y < block.y + block.height && collidedRec.width > 10){
                    player.y = block.y + player.height;
                }
            }
        }
        


        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            for (auto block : blocks)
            {
                DrawRectangleRec(block, RED);
            }
            DrawRectangleRec(player, GREEN);
            
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
