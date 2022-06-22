#include <raylib.h>
#include <cmath>
#include <time.h>
#include <vector>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Generate Random numbers.
    srand(time(NULL));

    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Pixel vector.
    std::vector<Vector2> pixels;

    Color colors[] = {
        RED,GREEN,BLUE,PURPLE,ORANGE,YELLOW,BLACK,BROWN
    };

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // Generating random pixels
        // maybe 600 is too much pixels u can make it 300 or less.
        for(int i = 0; i < 300; i++){
            for(int j = 0; j < 300; j++){
                Vector2 pix;
                pix.x = rand() % 600;
                pix.y = rand() % 600;
                pixels.push_back(pix);
            }
        }

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(WHITE);
            // <--- DRAW --->
            for(Vector2 pixel : pixels){
                DrawPixelV(pixel, colors[rand() % 8]);
            }
        EndDrawing();

        // Clear vector.
        pixels.clear();
    }
    
}
