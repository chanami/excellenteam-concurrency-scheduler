#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_SCHEDULER_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_SCHEDULER_H

#include <vector>
#include "time.h"
#include "shared_ptr.h"
#include "ITask.h"

typedef std::pair<shared_ptr<ITask>,Time > pairs;

class scheduler
{
public:
    scheduler() /*define heap*/;
    pairs get_next_pair();
    void run_tasks();

private:
    vector<paris> m_heap;

};

#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_CHANAMI_SCHEDULER_H
