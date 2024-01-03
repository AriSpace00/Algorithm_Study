#include "Timer.h"

#include <iostream>

Timer::Timer()
{
    QueryPerformanceFrequency(&m_frequency);
}

Timer::~Timer()
{
}

void Timer::Start()
{
    QueryPerformanceCounter(&m_beginTime);
}

void Timer::End()
{
    QueryPerformanceCounter(&m_endTime);
}

double Timer::GetElapsedTime()
{
    __int64 elapsedTime = m_endTime.QuadPart - m_beginTime.QuadPart;
    double duringtimeSec = (double)elapsedTime / (double)m_frequency.QuadPart;

    std::cout << "수행시간 : " << duringtimeSec * 1000 << "ms" << std::endl;

    return duringtimeSec;
}
