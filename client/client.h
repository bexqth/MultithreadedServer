#include <netinet/in.h>
#include <string>

class Client {
    private:
        int clientSocket;
        int serverSocket;
        sockaddr_in serverAddress;
    public:
        Client();
        bool connectToServer();
        void sendMessToServer(std::string message);
        void recieveMessFromServer();
        ~Client();
};