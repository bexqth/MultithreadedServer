#include <thread>
#include <vector>
#include "Worker.h"
#include "Storage.h"

class SimulationEngine
{
    private:
        std::vector<Worker*> workers;
        Storage storage;

    public:
        SimulationEngine();
        ~SimulationEngine();
        void addWorker(Worker* newWorker);
        void removeWorker(int workerId);
        void printWorkers();
};

