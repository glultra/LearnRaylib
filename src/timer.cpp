#include "timer.h"

void Timer::UpdateTime(float time){
    xValue = std::cos(time * speed);
    yValue = std::sin(time * speed);
    deltaTime = time - lastFrame;
    lastFrame = time;
    frame_count++;
}
