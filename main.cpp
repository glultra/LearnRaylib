#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <vector>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

#define BLOCK_SIZE      50

using namespace std;

vector<Rectangle> MakeTileblocks(float offset)
{
    vector<Rectangle> blocks;
    for (int i = 0; i < SCREEN_WIDHT / BLOCK_SIZE; i++)
    {
        for (int j = 0; j < SCREEN_HEIGHT / BLOCK_SIZE; j++)
        {
            Rectangle block;
            block.width = BLOCK_SIZE; block.height = BLOCK_SIZE;
            block.x = 0.0f + (BLOCK_SIZE + offset) * i;
            block.y = 0.0f + (BLOCK_SIZE + offset) * j;
            blocks.push_back(block);
        }   
    }
    return blocks;
}

int main(){
    // Enable MSAA 4X.
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Tile blocks.
    vector<Rectangle> blocks;
    blocks = MakeTileblocks(1.0f);

    // Tile color state.
    Color tile_color = RED;


    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        static int frame_count = 0;
        frame_count++;
        if(frame_count % 120 == 0){
            tile_color.r = GetRandomValue(0, 255);
            tile_color.g = GetRandomValue(0, 255);
            tile_color.b = GetRandomValue(0, 255);
            tile_color.a = 255;
        }

        static float offset = 0.0f;

        if(IsKeyDown(KEY_D)){
            blocks = MakeTileblocks(offset+=0.1f);
        }else if (IsKeyDown(KEY_A)){
            blocks = MakeTileblocks(offset-=0.1f);
        }

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            float fade_rate = 1.0f;
            for (int i = 0; i < blocks.size(); i++)
            {
                fade_rate = i % (SCREEN_WIDHT / BLOCK_SIZE) == 0 ? fade_rate-=0.07f : fade_rate;
                DrawRectangleRec(blocks[i], Fade(tile_color, fade_rate));
            }
            

        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
