#include <netinet/in.h>

class Server {
    private:
        int serverSocket;
        int clientSocket;
        sockaddr_in serverAddress;
    public:
        Server();
        void startServer();
        void handleClient();
        ~Server();
};