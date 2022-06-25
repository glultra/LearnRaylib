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
        std::vector<Rectangle> blocks;
        Vector2 offset;
        Vector2 position;

        void InitTilemap()
        {
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
                        block.x = position.x + (block.width + offset.x)    * j; 
                        block.y = position.y + (block.height + offset.y)   * i;
                        blocks.push_back(block);
                    }
                }
            }
        }

    public:
        Tilemap(Vector2 position, Vector2 offset){
            SetPosition(position);
            SetOffset(offset);
            InitTilemap();
        };

        // Protype functions.
        void Draw();
        void CheckCollision(Rectangle &player);
        void SetPosition(Vector2 position);
        void SetOffset(Vector2 offset);

};