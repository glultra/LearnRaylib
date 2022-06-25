#include <vector>
#include "../deps/include/raylib.h"

class Tilemap{
    private:
        const static int SIZE_X = 15; 
        const static int SIZE_Y = 8; 
        // Making the tilemap.
        const char tilemap[SIZE_Y][SIZE_X] = {
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' '},
            {'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        };
    public:
        std::vector<Rectangle> blocks;
        Tilemap(float position, float xoffset, float yoffset){
            // Initialize each block's position.
            for (int i = 0; i < SIZE_Y; i++) // 8
            {
                for (int j = 0; j < SIZE_X; j++) // 15
                {
                    if(tilemap[i][j] == ' ') continue;
                    if(tilemap[i][j] == '#'){
                        Rectangle block;
                        block.width     = 50;
                        block.height    = 50;
                        block.x = position + (block.width + xoffset)    * j; 
                        block.y = position + (block.height + yoffset)   * i;
                        blocks.push_back(block);
                    }
                    
                }
                
            }
            
        };

        // Protype functions.
        void Draw();
        void CheckCollision(Rectangle &player);

};