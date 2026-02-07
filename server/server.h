#include <netinet/in.h>
#include <thread>
#include <vector>

class Server {
    private:
        int serverSocket;
        //int clientSocket;
        sockaddr_in serverAddress;
        std::vector<std::thread> threads;
    public:
        Server();
        void startServer();
        void handleClient(int clientSocket);
        ~Server();
};