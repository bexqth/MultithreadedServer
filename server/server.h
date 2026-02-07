#include <netinet/in.h>

class Server {
    private:
        int serverSocket;
        //int clientSocket;
        sockaddr_in serverAddress;
        vector<thread> threads;
    public:
        Server();
        void startServer();
        void handleClient(int clientSocket);
        ~Server();
};