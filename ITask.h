#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_ITASK_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_ITASK_H

class ITask
{
public:
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds

private:

    unsigned long task_period;
};

#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_ITASK_H
