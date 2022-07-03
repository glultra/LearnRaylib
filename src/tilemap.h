#ifndef TILEMAP_H
#define TILEMAP_H

#include "../deps/include/raylib.h"
#include <vector>


class Tilemap{
    private:
        // Properties.
        const static int SIZE_X = 15; // Number of the columns.
        const static int SIZE_Y = 8; // Number of the rows.
        const char tilemap[SIZE_Y][SIZE_X] = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        };

        std::vector<Rectangle> blocks;
        Vector2 offset;
        Vector2 position;

        // Private Functions.
        void InitTilemap();

    public:
        // Constructors.
        Tilemap(Vector2 position, Vector2 offset){
            SetPosition(position);
            SetOffset(offset);
            this->InitTilemap();
        }

        // Function protypes.
        void Draw(Color color);
        void CheckCollision(Rectangle &player);
        void SetPosition(Vector2 position);
        void SetOffset(Vector2 offset);
};



#endif