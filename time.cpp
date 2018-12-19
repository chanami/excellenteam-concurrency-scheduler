#include "time.h"

Time::Time(unsigned long deltaTime) {

    clockid_t clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &m_time);

    unsigned long temp = deltaTime * 1000000 + m_time.tv_nsec;

    m_time.tv_sec += temp / 1000000000;
    m_time.tv_nsec = temp % 1000000000;
}

Time &Time::operator+(unsigned long deltaTime) {

    unsigned long temp = deltaTime * 1000000 + m_time.tv_nsec;

    m_time.tv_sec += temp / 1000000000;
    m_time.tv_nsec = temp % 1000000000;

    return *this;
}

bool Time::operator<(const Time &other) const {

    if (m_time.tv_sec == other.m_time.tv_sec)
        return m_time.tv_nsec < other.m_time.tv_nsec;

    return m_time.tv_sec < other.m_time.tv_sec;
}

void Time::sleep() const
{
    timespec delta;

    clockid_t clk_id;
    clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &delta);


    if (m_time.tv_sec < delta.tv_sec || (m_time.tv_sec == delta.tv_sec && m_time.tv_nsec < delta.tv_nsec))
    {
        std::cout << "Too late. not going to sleep" <<std::endl;
        return;
    }

    delta.tv_sec = m_time.tv_sec - delta.tv_sec - 1;

    unsigned long temp = 1000000000 + m_time.tv_nsec - delta.tv_nsec;
    delta.tv_sec += temp / 1000000000;
    delta.tv_nsec = temp % 1000000000;

    std::cout << "going to sleep for "<< delta.tv_sec << "." << delta.tv_nsec << std::endl;
    nanosleep(&delta,NULL);
}

Time & Time::operator=(unsigned long next_period){

    clockid_t clk_id;
    clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &m_time);

    next_period *= 1000000;
    next_period += m_time.tv_nsec;

    m_time.tv_nsec = next_period % 1000000000;
    m_time.tv_sec += next_period / 1000000000;

    return *this;
}