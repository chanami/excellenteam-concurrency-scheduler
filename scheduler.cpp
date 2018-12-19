#include<algorithm>
#include<iostream>
#include "scheduler.h"
#include <unistd.h>


Scheduler::Scheduler()
{
    //m_tasksHeap.push_back(std::make_pair(shared_ptr<ITask>(task),Time(task->getNextRunPeriod())));
    //  std::make_heap(m_tasksHeap.begin(), m_tasksHeap.end());
}

void Scheduler::run()
{
    while(!m_tasksHeap.empty())
    {
        std::cout << "after m_tasks.size():" << m_tasksHeap.size() << std::endl;

        STask* temp = getNextTask();
        ((*temp).second).sleep();
        (*(*temp).first).run();


        next_task_period_handler(temp);
    }

}


STask* Scheduler::getNextTask()
{
    pop_heap(m_tasksHeap.begin(), m_tasksHeap.end());
    STask * temp = &m_tasksHeap.back();

    std::cout<<"\n\n";
    return temp;

}

void Scheduler::appendTask(ITask* task)
{
    m_tasksHeap.push_back(std::make_pair(shared_ptr<ITask>(task),Time(task->getNextRunPeriod())));
    push_heap(m_tasksHeap.begin(), m_tasksHeap.end());
}

void Scheduler::next_task_period_handler(STask * temp)
{
    unsigned long next_period = (*(*temp).first).another_run();
    if(next_period == 0)
        m_tasksHeap.pop_back();

    else
    {
        ((*temp).second) = next_period;
        std::sort_heap (m_tasksHeap.begin(),m_tasksHeap.end());
    }
}
bool operator < (STask p1, STask p2)
{
    return !(p1.second < p2.second);
}


