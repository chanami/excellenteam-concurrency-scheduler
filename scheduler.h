#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_SCHEDULER_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_SCHEDULER_H

#include <vector>
#include "time.h"
#include "shared_ptr.h"
#include "ITask.h"

typedef std::pair<shared_ptr<ITask>,Time > task_pair;

class Scheduler
{
public:
    Scheduler(ITask *tasks) /*define heap*/;
    void run_tasks();

private:

    task_pair & get_next_pair();
    std::vector<task_pair> m_heap;

};

#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_SCHEDULER_H
