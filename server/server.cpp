#include "server.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>

using namespace std;

Server::Server() {
    this->storage = 100;
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(8080);
    this->serverAddress.sin_addr.s_addr = INADDR_ANY;
    //bind(this->serverSocket, (struct sockaddr*)&this->serverAddress, sizeof(this->serverAddress))   
    if (::bind(this->serverSocket, (struct sockaddr*)&this->serverAddress, sizeof(this->serverAddress)) < 0) {
        perror("Bind failed");
        exit(1);
    }
     //binding the socket to this server
}

void Server::startServer()
{
    listen(this->serverSocket, 5);

    while(true) {
        cout << "waiting for connecting " << endl;

        int clientSocket = accept(this->serverSocket, nullptr, nullptr);
        cout << "connected client " << clientSocket << endl;

        unique_lock clientSocketsLock(this->clientSocketsMutex);
        this->clientSockets.push_back(clientSocket);
        thread clientThread(&Server::handleClient, this, clientSocket);
        clientSocketsLock.unlock();
        
        clientThread.detach();
    }
}

void Server::handleClient(int clientSocket)
{
    while (true) {
        char buffer[1024] = {0};
        int bytes = recv(clientSocket, buffer, sizeof(buffer), 0);
        
        if(bytes <= 0) {
            cout << "Client disconnected: " << endl;
            close(clientSocket);
            break;
        } else {
            unique_lock<mutex> lock(this->mtx);
            int valueRequest = atoi(buffer);
            if (this->storage - valueRequest < 0) {
                cout << "No enough in storage " << endl;
            } else {
                this->storage -= valueRequest;
                cout << "Client took " << valueRequest << endl;
                cout << "Left in storage " << this->storage << endl;
                std::string responseToClient = "U took " + to_string(valueRequest) + ". Left in storage " + to_string(this->storage) + "\n"; 
                send(clientSocket, responseToClient.c_str(), responseToClient.length(), 0);
            }
            //cout << "Message from client: " <<  clientSocket << " "<< buffer << endl;
            lock.unlock();
        }

    }
}

Server::~Server()
{
    //close(this->clientSocket);
    close(this->serverSocket);
}
