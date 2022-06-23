#include "timer.h"
#include <cmath>

void Timer::UpdateTime(float time){
    xValue = std::cos(time); // from +1.0 to -1.0
    yValue = std::sin(time); // from -1.0 to +1.0
    xValuePos = (xValue / 2.0) + 0.5; // from 1.0 to 0.0
    yValuePos = (yValue / 2.0) + 0.5; // from 0.0 to 1.0

    deltaTime = time - lastFrame;
    lastFrame = time;
    
    frame_count++;
}
