#include "storage.h"
#include <iostream>
#include <cstring>
using namespace std;

Storage::Storage()
{
    this->itemMap.insert({"wood", 100});
    this->itemMap.insert({"stone", 120});
    this->itemMap.insert({"food", 230});
}

Storage::~Storage()
{
}

void Storage::printStorage()
{
    unique_lock<mutex> storageLock(this->storageMutex);
    cout << "Storage: " << endl;
    for (const auto& it : this->itemMap)
    {
        cout << it.first << "   " << it.second << endl;
                // key                 // value
    }
    storageLock.unlock(); 
}

bool Storage::updateItemValue(std::string itemName, int value)
{
    unique_lock<mutex> storageLock(this->storageMutex);
    auto item = this->itemMap.find(itemName);
    if (item != this->itemMap.end()) {
        this->itemMap[itemName] = this->itemMap[itemName] + value;
        storageLock.unlock();
        return true;
    }
    storageLock.unlock();
    return false;
}
