#include "tilemap.h"

void Tilemap::InitTilemap(){
    // Initialize each block's position depends to the tilemap.
    for (int i = 0; i < SIZE_Y; i++)
    {
        for(int j = 0; j < SIZE_X; j++){
            if(tilemap[i][j] == ' ') continue; // Skip.
            if(tilemap[i][j] == '#'){
                Rectangle block;
                block.width = 50;
                block.height = 50;
                block.x = position.x + (block.width  + offset.x) * j; // Add each column's block.
                block.y = position.y + (block.height + offset.y) * i; // Add each row's block.
                blocks.push_back(block);
            }
        }
    }
    
}
void Tilemap::Draw(Color color){
    for (auto block : blocks)
    {
        DrawRectangleRec(block, color);
    }
    
}
void Tilemap::CheckCollision(Rectangle &player){
    
}
void Tilemap::SetPosition(Vector2 position){
    this->position = position;
}
void Tilemap::SetOffset(Vector2 offset){
    this->offset = offset;
}