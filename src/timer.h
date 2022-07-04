#ifndef TIMER_H
#define TIMER_H

#include <cmath>

class Timer{
    public:
        // Timer Properties.
        float xValue;
        float yValue;
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
        float speed = 2.0f; // For auto movements.
        int frame_count = 0;

        Timer(){}

        // Function protypes.
        void UpdateTime(float time);
};


#endif