#pragma once
#include <windows.h>

class Timer
{
public:
    Timer();
    ~Timer();

    void Start();
    void End();

    double GetElapsedTime();

private:
    LARGE_INTEGER m_frequency;
    LARGE_INTEGER m_beginTime;
    LARGE_INTEGER m_endTime;
};

