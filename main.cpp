#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <sstream>

#define SCREEN_WIDHT    600
#define SCREEN_HEIGHT   600
#define SCREEN_TITLE    "Raylib"

 bool isButtonHover;
 bool isButtonHover2;
 bool isSliderHover;
 bool isDarkMode = true;
 int current_item = 1; // default 
// Gui function protypes.
void GuiSliderMusic(Rectangle rec, Music& music, Color color);
void GuiPlayButton(Vector2 position, Music& music, float radius, Color bgColor, Color fgColor);
void GuiPlayButton(Vector2 position, Music music[],Texture texture, float radius, Color bgColor, Color fgColor, std::string action);

int main(){
    // Enable MSAA 4X.
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    
    // Initialize window.
    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_TITLE);

    // Initialize Audio Device.
    InitAudioDevice();

    // Music object.
    Music quraan_lists[] = { 
        LoadMusicStream("./res/music/quraan/100.mp3"),
        LoadMusicStream("./res/music/quraan/101.mp3"), // Default
        LoadMusicStream("./res/music/quraan/102.mp3"),
    };

    std::string surat_names[] = {
        "100: Al-'Adiyat",
        "101: Al-Qari'ah",
        "102: At-Takathur",
    };

    // music.looping = false;

    PlayMusicStream(quraan_lists[1]);

    // Slider rec.
    Rectangle seek_rec{50, 400, 300, 10};
    seek_rec.x = GetScreenWidth() / 2.0f - seek_rec.width/2.0f;

    // Texture2D.
    Texture2D texture = LoadTexture("./res/images/holyquraan.png");
    texture.width   = 212;
    texture.height  = 212;

    Texture2D next_track = LoadTexture("./res/icons/forward.png");
    next_track.width   = 35;
    next_track.height  = 35;

    Texture2D back_track = LoadTexture("./res/icons/backward.png");
    back_track.width   = 35;
    back_track.height  = 35;

    Texture2D dark_mode = LoadTexture("./res/images/dark-mode-toggle.png");
    dark_mode.width   = 101;
    dark_mode.height  = 52;

    Texture2D light_mode = LoadTexture("./res/images/light-mode-toggle.png");
    light_mode.width   = 101;
    light_mode.height  = 52;


    // Target FPS.
    SetTargetFPS(60);

    // Render loop.
    while (!WindowShouldClose())
    {
        // <----- UPDATE ----->
        float tex_centerx = GetScreenWidth()/2.0f  - texture.width/2.0f;
        float tex_centery = GetScreenWidth()/2.0f  - texture.height/2.0f;
        Vector2 mode_pos = Vector2{GetScreenWidth() - 110.0f, 20.0f};

        bool isModeHover = CheckCollisionPointRec(GetMousePosition(), Rectangle{mode_pos.x, mode_pos.y, 101.0f, 52.0f});
        if(isModeHover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            // Toggle Button.
            isDarkMode = isDarkMode ? false : true;
        }

        if(isButtonHover || isSliderHover || isButtonHover2 || isModeHover){
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }else{
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }
        
        // Update Music Buffer.
        UpdateMusicStream(quraan_lists[current_item]);

        // <----- RENDER ----->
        BeginDrawing();
            // Clear Background
            ClearBackground(isDarkMode ? Color{13,17,23,255} : WHITE);
            // <--- DRAW --->
            DrawTexture(texture, tex_centerx, tex_centery - 100, isDarkMode ? WHITE : GOLD);
            GuiPlayButton(Vector2{GetScreenWidth()/2.0f, GetScreenHeight()/2.0f + 200}, quraan_lists[current_item], 50, isDarkMode ? SKYBLUE : GOLD, isDarkMode ?  WHITE : BLACK);
            GuiPlayButton(Vector2{GetScreenWidth()/2.0f + 100, GetScreenHeight()/2.0f + 200}, quraan_lists, next_track, 35, isDarkMode ? SKYBLUE : GOLD, isDarkMode ?  WHITE : BLACK, "next");
            GuiPlayButton(Vector2{GetScreenWidth()/2.0f - 100, GetScreenHeight()/2.0f + 200}, quraan_lists, back_track, 35, isDarkMode ? SKYBLUE : GOLD, isDarkMode ?  WHITE : BLACK, "back");
            GuiSliderMusic(seek_rec, quraan_lists[current_item], isDarkMode ? SKYBLUE : GOLD);
            DrawText(surat_names[current_item].c_str(), GetScreenWidth()/2.0f - MeasureText(surat_names[current_item].c_str(), 30)/2.0f, GetScreenHeight()/2.0f + 50, 30, isDarkMode ? WHITE : BLACK);
            if(isDarkMode){
                DrawTextureV(dark_mode,mode_pos, isModeHover ? SKYBLUE : Fade(SKYBLUE, 0.7f));
            }
            else{
                DrawTextureV(light_mode,mode_pos, isModeHover ? Fade(GOLD, 0.7) : GOLD);
            }
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
    isSliderHover  = CheckCollisionPointRec(GetMousePosition(), rec);

    if(isSliderHover && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        float dx = GetMousePosition().x - rec.x;
        PauseMusicStream(music);
        slider.width = dx;
        SeekMusicStream(music, dx / (rec.width / max_second)); // Responsive depends to rec.width.
    }else{
        // ResumeMusicStream(music);
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
    if(isDarkMode)
        DrawRectangleRounded(slider, 1.0f, 7, isSliderHover ? color : Fade(color, 0.9f)); // Slider
    else
        DrawRectangleRounded(slider, 1.0f, 7, isSliderHover ? Fade(color, 0.9f) : color); // Slider

    DrawRectangleRounded(rec, 1.0f, 7, Fade(color, 0.3f)); // Rec
    DrawRectangleRoundedLines(rec, 3, 1.0f, 7, Fade(color, 0.7f)); // Border
    DrawCircleV(circle_center, point_radius, BLUE);
    DrawCircleLines(circle_center.x, circle_center.y, point_radius, BLACK);
    DrawText(ss.str().c_str(), rec.x - MeasureText(ss.str().c_str() , 23) - 23, rec.y, 23, isDarkMode ?  WHITE : BLACK);
    ss.clear();
    ss = std::stringstream("");
    ss << (int)max_second / 60 << ":"; // first show mins
    ss << (int)max_second % 60;
    DrawText(ss.str().c_str(), rec.x + rec.width + MeasureText(ss.str().c_str() , 23) - 18, rec.y, 23, isDarkMode ? WHITE : BLACK);
}

void GuiPlayButton(Vector2 position, Music& music, float radius, Color bgColor, Color fgColor){
    // Update 
    static bool isPlayed = true;
    isButtonHover = CheckCollisionPointCircle(position, GetMousePosition(), radius);
    float point = radius / 3.0f; 

    if(isButtonHover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        isPlayed = isPlayed ? false : true;
    }

    // Render
    if(isDarkMode)
        DrawCircleV(position, radius, isButtonHover ? bgColor: Fade(bgColor, 0.7f));
    else
        DrawCircleV(position, radius, isButtonHover ? Fade(bgColor, 0.7f) : bgColor);

    if(isPlayed){
        ResumeMusicStream(music);
        // Resume Symbol Shape.
        DrawRectangle(position.x - point, position.y - point, radius/4.0, radius/1.5, fgColor); // Left Rectangle
        DrawRectangle(position.x + point - (radius/4.0f), position.y - point, radius/4.0, radius/1.5, fgColor); // Right Rectangle
    }else{
        // Triangle Symbol Shape.
        PauseMusicStream(music);
        DrawTriangle(
            Vector2{position.x - point, position.y - point},
            Vector2{position.x - point, position.y + point},
            Vector2{position.x + point, position.y },
            fgColor
        );
    }

}

void GuiPlayButton(Vector2 position, Music music[],Texture texture, float radius, Color bgColor, Color fgColor, std::string action)
{
    // Update 
    isButtonHover2 = CheckCollisionPointCircle(position, GetMousePosition(), radius);
    
    if(isButtonHover2){
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }

    if(isButtonHover2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(action == "next")
            if(current_item < 2)
            {
                current_item++;
                PlayMusicStream(music[current_item]);
            }
            
        if(action == "back")
            if(current_item > 0){
                current_item--;
                PlayMusicStream(music[current_item]);
            }
    }

    // Render
    if(isDarkMode)
        DrawCircleV(position, radius, isButtonHover2 ? bgColor: Fade(bgColor, 0.7f));
    else
        DrawCircleV(position, radius, isButtonHover2 ? Fade(bgColor, 0.7f) : bgColor);

    DrawTexture(texture, position.x - radius/2.0f, position.y - radius/2.0f, fgColor);
    
}