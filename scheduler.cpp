#include "scheduler.h"

Scheduler::Scheduler(ITask *tasks)
{
    for(ITask * ptr = tasks; ptr ; ++ptr)
    {
        m_heap.push_back(std::make_pair(shared_ptr<ITask>(ptr),Time(clock()) + ptr->getNextRunPeriod()));
    }
    std::make_heap(m_heap.begin(),m_heap.end());

}

