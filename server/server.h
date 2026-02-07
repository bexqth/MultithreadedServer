#include <netinet/in.h>
#include <thread>
#include <vector>

class Server {
    private:
        int serverSocket;
        int storage; //shared data
        std::mutex mtx;
        //int clientSocket;
        sockaddr_in serverAddress;
        std::vector<int> clientSockets;
        std::mutex clientSocketsMutex;
    public:
        Server();
        void startServer();
        void handleClient(int clientSocket);
        ~Server();
};