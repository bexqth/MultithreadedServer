#include <map>

class Storage {
    private:
        std::map<std::string, int> itemMap;
        std::mutex storageMutex;
    public:
        Storage();
        ~Storage();
        void printStorage();
        bool updateItemValue(std::string itemName, int value);
}