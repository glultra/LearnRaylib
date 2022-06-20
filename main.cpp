#include <raylib.h>

int main(){
    InitWindow(600, 600, "Hello World");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLUE);
        EndDrawing();
    }
    
}