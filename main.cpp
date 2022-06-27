#include <raylib.h>
#include <vector>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

int main(){
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // List of colors.
    Color colors[] = {
        GOLD,RED,GREEN,BLUE,PURPLE,
        SKYBLUE,ORANGE,PINK,LIME,BEIGE
    };

    // Pixels.
    std::vector<Vector2> pixels;

    // Set Each pixel's position.
    for (int i = 0; i < 50000; i++)
    {
        Vector2 pixel;
        pixel.x = GetRandomValue(0, SCREEN_WIDHT);
        pixel.y = GetRandomValue(0, SCREEN_HEIGHT);
        pixels.push_back(pixel);
    }
    

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // ClearBackground(WHITE);
            // <--- DRAW --->
            for (auto &pixel : pixels)
            {
                DrawPixel(pixel.x, pixel.y, colors[GetRandomValue(0, 9)]);
            }
            

        EndDrawing();
    }
    
}
