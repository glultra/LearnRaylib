#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

// Gui function protypes.
void GuiSliderMusic(Rectangle rec, Music& music, Color color);

int main(){
    // Enable MSAA 4X.
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Initialize Audio Device.
    InitAudioDevice();

    // Music object.
    Music music = LoadMusicStream("./res/music/wisdom.mp3");
    // music.looping = false;

    PlayMusicStream(music);

    // Slider rec.
    Rectangle seek_rec{50, 300, 400, 40};


    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        
        // Update Music Buffer.
        UpdateMusicStream(music);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            GuiSliderMusic(seek_rec, music, SKYBLUE);
        EndDrawing();
    }

    // De Initialization of OpenGL Context.
    CloseWindow();
    
}

void GuiSliderMusic(Rectangle rec, Music& music, Color color){
    // Update
    Rectangle slider = rec;

    float time_played   = GetMusicTimePlayed(music);
    float max_second    = GetMusicTimeLength(music);
    bool isSliderHover  = CheckCollisionPointRec(GetMousePosition(), rec);

    if(isSliderHover && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        float dx = GetMousePosition().x - rec.x;
        PauseMusicStream(music);
        slider.width = dx;
        SeekMusicStream(music, dx / (rec.width / max_second)); // Responsive depends to rec.width.
    }else{
        ResumeMusicStream(music);
        slider.width = (rec.width / max_second) * time_played; // Responsive depends to rec.width.
    }

    // Point slider.
    float point_radius  = rec.height / 2;
    Vector2 circle_center = Vector2{slider.x + slider.width, slider.y + point_radius};


    // Render
    DrawRectangleRounded(slider, 1.0f, 7, color); // Slider
    DrawRectangleRounded(rec, 1.0f, 7, Fade(color, 0.3f)); // Rec
    DrawRectangleRoundedLines(rec, 3, 1.0f, 7, Fade(color, 0.7f)); // Border
    DrawCircleV(circle_center, point_radius, BLUE);
    DrawCircleLines(circle_center.x, circle_center.y, point_radius, BLACK);

}
