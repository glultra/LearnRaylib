#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include <vector>
#include "../deps/include/raylib.h"

class GuiTileButtons{
    private:
        const static int block_size = 10;
        Color colors[block_size] = {
            YELLOW, GREEN, PURPLE, BLUE, VIOLET,
            ORANGE, LIME, GOLD, SKYBLUE, PINK,
        };
        std::vector<Rectangle> buttons;

        void InitButtonTiles(){
            // Set each block's position.
            for (int i = 0; i < block_size; i++)
            {
                Rectangle button;
                button.width    = 50;
                button.height   = 50;
                button.x = 150 + 70 * (i % 5); // 5 block in a row
                button.y = 300 + 70 * (i / 5); // when ever it reached to 5 index it will increase.
                buttons.push_back(button);
            }
            
        }

    public:
        GuiTileButtons(){
            this->InitButtonTiles();
        }

        void CheckCollision(Color& color_state){
            for (int i = 0; i < buttons.size(); i++)
            {
                bool isCollided = CheckCollisionPointRec(GetMousePosition(), buttons[i]);
                if(isCollided && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    color_state = colors[i];
                }
            }
            
        }

        void Draw(){
            for (int i = 0; i < block_size; i++)
            {
                DrawRectangleRec(buttons[i], colors[i]);
            }
            
        }

};


#endif