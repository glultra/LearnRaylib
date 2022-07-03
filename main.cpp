#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <vector>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Enable MSAA 4X.
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Texture obj.
    Texture light = LoadTexture("./res/images/light.png");
    Color color_state = WHITE;

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
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawTexture(light, 170, 20, color_state);
            for (int i = 0; i < buttons.size(); i++)
            {
                // Check for hovering on the button.
                bool isHovered = CheckCollisionPointRec(GetMousePosition(), buttons[i]);

                // if Rollevered.
                if(isHovered && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    // I need to change the color.
                    DrawRectangleRec(buttons[i], Fade(colors[i], 0.3f));
                }
                else
                    DrawRectangleRec(buttons[i], colors[i]);
                
                if(isHovered){
                    DrawRectangleLinesEx(buttons[i], 4, 
                        Fade(GRAY, 0.6)
                    );
                }   
            }

            
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}
