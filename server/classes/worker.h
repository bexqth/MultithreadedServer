#include <string>

class Worker {
    private:
        int id;
        std::string name;
        std::string role;
    public:
        Worker(int id, const std::string& name, const std::string& role);
        ~Worker();
        std::string getName() const;
        int getId() const;
        std::string getRole() const;
};