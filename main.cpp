#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <sstream>

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
    Music music = LoadMusicStream("./res/music/quraan/101.mp3");
    // music.looping = false;

    PlayMusicStream(music);

    // Slider rec.
    Rectangle seek_rec{50, 400, 300, 10};
    seek_rec.x = GetScreenWidth() / 2.0f - seek_rec.width/2.0f;

    // Texture2D.
    Texture2D texture = LoadTexture("./res/images/holyquraan.png");
    texture.width   = 212;
    texture.height  = 212;


    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float tex_centerx = GetScreenWidth()/2.0f  - texture.width/2.0f;
        float tex_centery = GetScreenWidth()/2.0f  - texture.height/2.0f;
        
        // Update Music Buffer.
        UpdateMusicStream(music);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(Color{13,17,23,255});
            // <--- DRAW --->
            DrawTexture(texture, tex_centerx, tex_centery - 100, WHITE);
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

    // Format: Convert second to minute.
    // Second to minute -> minute = second/60
    std::stringstream ss;
    ss << (int)time_played / 60 << ":"; // first show mins
    ss << (int)time_played % 60;

    // Render
    DrawRectangleRounded(slider, 1.0f, 7, color); // Slider
    DrawRectangleRounded(rec, 1.0f, 7, Fade(color, 0.3f)); // Rec
    DrawRectangleRoundedLines(rec, 3, 1.0f, 7, Fade(color, 0.7f)); // Border
    DrawCircleV(circle_center, point_radius, BLUE);
    DrawCircleLines(circle_center.x, circle_center.y, point_radius, BLACK);
    DrawText(ss.str().c_str(), rec.x - MeasureText(ss.str().c_str() , 23) - 23, rec.y, 23, GREEN);
    ss.clear();
    ss = std::stringstream("");
    ss << (int)max_second / 60 << ":"; // first show mins
    ss << (int)max_second % 60;
    DrawText(ss.str().c_str(), rec.x + rec.width + MeasureText(ss.str().c_str() , 23) - 20, rec.y, 23, GREEN);
}
