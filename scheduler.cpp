#include "scheduler.h"

scheduler::scheduler(Itask *tasks)
{
    for(Itask * ptr = tasks; ptr ; ++ptr)
    {
        m_heap.push_back(std::make_pair(shared_ptr<Itask>(ptr),Time(clock()) + ptr->getNextRunPeriod()));
    }
    std::make_heap(m_heap.begin(),m_heap.end());
}

