#include "server.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

Server::Server() {
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(8080);
    this->serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(this->serverSocket, (struct sockaddr*)&this->serverAddress, sizeof(this->serverAddress)); //binding the socket to this server
}

void Server::startServer()
{
    listen(this->serverSocket, 5);
    this->clientSocket = accept(this->serverSocket, nullptr, nullptr);
}

void Server::handleClient()
{
    while (true) {
        char buffer[1024] = {0};
        int bytes = recv(this->clientSocket, buffer, sizeof(buffer), 0);

        if(bytes <= 0) {
            cout << "Client disconnected: " << endl;
            close(this->clientSocket);
            break;
        }

        cout << "Message from client: " << buffer << endl;


    }
}

Server::~Server()
{
    close(this->clientSocket);
    close(this->serverSocket);
}
