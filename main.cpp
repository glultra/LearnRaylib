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

    PlayMusicStream(music);


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
            GuiSliderMusic(Rectangle{50, 300, 400, 30}, music, SKYBLUE);
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

    bool isSliderHover = CheckCollisionPointRec(GetMousePosition(), rec);

    if(isSliderHover && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        float dx = GetMousePosition().x - rec.x;
        PauseMusicStream(music);
        slider.width = dx;
        SeekMusicStream(music, dx / (rec.width / max_second)); // Responsive depends to rec.width.
    }else{
        ResumeMusicStream(music);
        slider.width = (rec.width / max_second) * time_played; // Responsive depends to rec.width.
    }


    // Render
    DrawRectangleRec(slider, color);
    DrawRectangleLinesEx(rec, 3, Fade(color, 0.3f));

}
