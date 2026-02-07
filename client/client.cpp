#include "client.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

Client::Client()
{
    this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(8080);
    this->serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
}

bool Client::connectToServer()
{
    int con = connect(this->clientSocket, (struct sockaddr*)&this->serverAddress, sizeof(this->serverAddress));
    if (con != -1) {
        cout << "Connected to server " << endl;
        return true;
    } else {
        perror("Connect failed"); 
    }
    return false;
}

void Client::sendMessToServer(string message)
{
    send(this->clientSocket, message.c_str(), message.length(), 0);
}

void Client::recieveMessFromServer()
{
    char buffer[1024] = {0};
    int bytes = recv(this->clientSocket, buffer, sizeof(buffer), 0);
    if (bytes > 0) {
        cout << "Server answer: " << buffer << endl;
    } else {
        cout << "Connection lost" << endl;
    }
}

Client::~Client()
{
    close(this->clientSocket);
}
