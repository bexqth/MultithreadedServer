#include "worker.h"


using namespace std;

Worker::Worker(int id, const std::string &name, const std::string &role) : id(id), name(name), role(role)
{
    
}

Worker::~Worker()
{

}

std::string Worker::getName() const
{
    return this->name;
}

int Worker::getId() const
{
    return this->id;
}

std::string Worker::getRole() const
{
    return this->role;
}
