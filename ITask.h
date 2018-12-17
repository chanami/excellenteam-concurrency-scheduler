#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_ITASK_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_ITASK_H

class ITask
{
public:

    ITask(unsigned long);
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds

private:

    unsigned long task_period;
};


class ITask_printer:public ITask
{
public:
    ITask_printer(unsigned long);
    void run();
    unsigned long getNextRunPeriod() = 0; // in milliseconds

private:

    unsigned long task_period;
};

class ITask_Anti_Virus:public ITask
{
public:
    ITask_Anti_Virus(unsigned long);
    void run();
    unsigned long getNextRunPeriod() = 0; // in milliseconds

private:

    unsigned long task_period;
};

class ITask_Timer:public ITask
{
public:
    ITask_Timer(unsigned long);
    void run();
    unsigned long getNextRunPeriod() = 0; // in milliseconds

private:

    unsigned long task_period;
};
#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_ITASK_H
