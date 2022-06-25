#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include "src/tilemap.h"
#include <vector>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Texture obj.
    Texture light = LoadTexture("./res/images/light.png");
    Color color_state = WHITE;
    bool isCollided = false;


    // Colors
    Color colors[] = {
        YELLOW, BLUE, GREEN, PINK, ORANGE,
        PURPLE, GOLD, BEIGE, SKYBLUE, LIME,
    };

    // Buttons.
    std::vector<Rectangle> buttons;

    // Set each button's position.
    for (int i = 0; i < 10; i++)
    {
        Rectangle button;
        button.width = 50;
        button.height= 50;
        button.x = 130 + 70 * (i % 5);
        button.y = 300 + 70 * (i / 5);
        buttons.push_back(button);
    }
    

    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // Checking collision mouse with each button.
        for (int i = 0; i < buttons.size(); i++)
        {
            isCollided = CheckCollisionPointRec(GetMousePosition(), buttons[i]);
            if(isCollided && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                color_state = colors[i];
            }
        }
        

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawTexture(light, 170, 10, color_state);
            for (int i = 0; i < buttons.size(); i++)
            {
                DrawRectangleRec(buttons[i], colors[i]);
                isCollided = CheckCollisionPointRec(GetMousePosition(), buttons[i]);
                if(isCollided){
                    DrawRectangleLinesEx(buttons[i], 4, 
                        Fade(BLACK, 0.6)
                    );
                }   
            }

            
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
