

#include "ITask.h"

ITask::~ITask(){}

Printer::Printer(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
}

Printer::~Printer(){}

unsigned long Printer::getNextRunPeriod() {
    return m_timeToNextRun;
}

void Printer::run() {
    std::cout << "Printer Task Running" << std::endl;
}

unsigned long Printer::another_run()
{
    std::cout << "Printer another Run" << std::endl;

    unsigned long ran = (rand() % 10)*1000;
    return ran;
}

ConnectionTest::ConnectionTest(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
}

ConnectionTest::~ConnectionTest(){}


unsigned long ConnectionTest::getNextRunPeriod() {
    return m_timeToNextRun;
}

void ConnectionTest::run() {
    std::cout << "ConnectionTest Task Running" << std::endl;
}

unsigned long ConnectionTest::another_run() {
    unsigned long ran = (rand() % 10)*1000;
    return ran;
}
AntiVirus::~AntiVirus(){}

AntiVirus::AntiVirus(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
}

unsigned long AntiVirus::getNextRunPeriod() {
    return m_timeToNextRun;
}

void AntiVirus::run() {
    std::cout << "AntiVirus Task Running" << std::endl;
}

unsigned long AntiVirus::another_run() {
    unsigned long ran = (rand() % 10)*1000;
    return ran;
}