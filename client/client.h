#include <netinet/in.h>
class Client {
    private:
        int clientSocket;
        sockaddr_in serverAddress;
    public:
        Client();
        void connectToServer();
        void sendMessToServer(string message);
        ~Client();
};