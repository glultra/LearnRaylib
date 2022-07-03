#include "tilemap.h"

void Tilemap::Draw(){
    for (auto block : blocks)
    {
        DrawRectangleRec(block, RED);   
    }

} 