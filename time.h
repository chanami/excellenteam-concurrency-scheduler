
#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_TIME_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_TIME_H

class Time
{
public:
    Time(unsigned long);

    Time & operator + (unsigned long other);
    bool operator < (const Time & time )const;
    bool operator == (const Time & time)const;

private:
    long time_task;
};
#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_TIME_H
