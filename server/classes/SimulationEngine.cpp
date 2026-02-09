#include "SimulationEngine.h"
#include <iostream>
#include <cstring>
using namespace std;

SimulationEngine::SimulationEngine()
{

}

SimulationEngine::~SimulationEngine()
{
    for (int i = 0; i < this->workers.size(); i++)
    {
        delete this->workers[i];
    }
    
}

void SimulationEngine::addWorker(Worker *newWorker)
{
    this->workers.push_back(newWorker);
}

void SimulationEngine::removeWorker(int workerId)
{
    for(int i = 0; i < this->workers.size(); i++) {
        Worker* worker = this->workers[i];
        if(worker->getId() == workerId) {
            delete worker;
            this->workers.erase(this->workers.begin() + i);
            break;
        }
    }
}

void SimulationEngine::printWorkers()
{
    for (int i = 0; i < this->workers.size(); i++)
    {
        Worker* worker = this->workers[i];
        cout << "["<< worker->getRole() << ", " << worker->getId() << "] " << worker->getName() << endl;
    }
    
}
