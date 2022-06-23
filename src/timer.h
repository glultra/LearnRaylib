#ifndef TIMER_H
#define TIMER_H

class Timer{
    public:
        // Timer Properties.
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
        float xValue;
        float xValuePos;
        float yValue;
        float yValuePos;
        int frame_count = 0;

        Timer(){}

        // Function protypes.
        void UpdateTime(float time);
};

#endif