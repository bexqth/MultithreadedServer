#include <server.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

Server::Server() {
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(8080);
    this->serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(this->serverSocket, (struct sockaddr*)&this->serverAddress, sizeof(this->serverAddress)); //binding the socket to this server
}

void Server::startServer()
{

}

Server::~Server()
{
    close(this->serverSocket);
}
