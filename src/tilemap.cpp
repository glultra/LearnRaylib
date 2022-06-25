#include "tilemap.h"

void Tilemap::Draw(Color color){
    for (auto block : blocks)
    {
        DrawRectangleRec(block, color);   
    }
        
}

void Tilemap::CheckCollision(Rectangle& player){
    for (auto block : blocks)
    {
        bool isCollided = CheckCollisionRecs(player, block);
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
    
}
void Tilemap::SetPosition(Vector2 position){
    this->position = position;
    blocks.clear();
    InitTilemap();
}
void Tilemap::SetOffset(Vector2 offset){
    this->offset = offset;
    blocks.clear();
    InitTilemap();
}