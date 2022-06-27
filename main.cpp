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

    // List of colors.
    Color colors[] = {
        YELLOW, BLUE, GREEN, PINK, ORANGE,
        PURPLE, GOLD, BEIGE, SKYBLUE, LIME,
    };

    std::string color_names[] = {
        "YELLOW", "BLUE", "GREEN", "PINK", "ORANGE",
        "PURPLE", "GOLD", "BEIGE", "SKYBLUE", "LIME",
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
        Vector2 mouse_pos = GetMousePosition();

        // Checking collision mouse with each button.
        for (int i = 0; i < buttons.size(); i++)
        {
            // Check if Mouse hovered on the button.
            bool isCollided = CheckCollisionPointRec(GetMousePosition(), buttons[i]);

            // Check if hovered and clicked.
            if(isCollided && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                color_state = colors[i];
            }
        }
        

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            // ClearBackground(Color{13,17,23,255});
            ClearBackground(WHITE);
            // <--- DRAW --->
            DrawTexture(light, 170, 20, color_state);
            for (int i = 0; i < buttons.size(); i++)
            {
                // Check for hovering on the button.
                bool isHovered = CheckCollisionPointRec(GetMousePosition(), buttons[i]);
                std::string color_name = color_names[i];
                float centeredX = MeasureText(color_name.c_str(), 10)/2; 

                // if Rollevered.
                if(isHovered && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    // I need to change the color.
                    DrawRectangleRounded(buttons[i], 0.3, 300, Fade(colors[i], 0.3f));
                }
                else
                    DrawRectangleRounded(buttons[i], 0.3, 300, Fade(colors[i], 0.6f));
                
                if(isHovered){
                    DrawRectangleRoundedLines(buttons[i],0.3, 300, 4, Fade(WHITE, 0.6));
                    DrawRectangleRounded( Rectangle{mouse_pos.x - centeredX - 3, mouse_pos.y - 33, 10 + centeredX * 2, 20}, 0.3, 300, Fade(GRAY, 0.9));
                    DrawText(color_name.c_str(), mouse_pos.x - centeredX, mouse_pos.y - 30, 10, colors[i]);
                }   
            }

            
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
