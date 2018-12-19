#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_SCHEDULER_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_SCHEDULER_H

#include <vector>
#include "ITask.h"
#include "shared_ptr.h"
#include "time.h"

typedef std::pair<shared_ptr<ITask>, Time> STask;

class Scheduler{
public:

    Scheduler();

    void appendTask(ITask* task);
    void run();
    void next_task_period_handler(STask * temp);

private:

    STask * getNextTask();

    std::vector<STask> m_tasksHeap;
};

bool operator < (STask p1, STask p2);

#endif
