#include <netinet/in.h>
#include <string>
#include <thread>

class Client {
    private:
        int clientSocket;
        int serverSocket;
        sockaddr_in serverAddress;
        std::thread recievingMessThread;
    public:
        Client();
        bool connectToServer();
        void sendMessToServer(std::string message);
        void recieveMessFromServer();
        void handleUserInput();
        void listenToServer();
        ~Client();
};