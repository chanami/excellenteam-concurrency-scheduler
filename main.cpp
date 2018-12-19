#include <time.h>
#include <iostream>
#include "scheduler.h"
#include "ITask.h"

using namespace std;

int main()
{

    Printer * p1 = new Printer(5000);
    AntiVirus * av1 = new AntiVirus(7000);
    ConnectionTest * ct = new ConnectionTest(9000);
    Scheduler * sc = new Scheduler();
    sc->appendTask(p1);
    sc->appendTask(av1);
    sc->appendTask(ct);
    sc->run();


    return 0;
}
