#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_TIME_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_TIME_H

#include <time.h>
#include <iostream>

using namespace std;
typedef struct timespec timespec;

class Time{
public:
    Time(unsigned long);
    Time & operator=(unsigned long next_period);

    Time& operator + (unsigned long);
    bool operator < (const Time&) const;

    void sleep() const;

private:

    timespec m_time;

};


#endif
