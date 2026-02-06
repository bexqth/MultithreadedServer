#include "client.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

Client::Client()
{
    this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(8080);
    this->serverAddress.sin_addr.s_addr = INADDR_ANY;
}

void Client::connectToServer()
{
    int con = connect(this->clientSocket, (struct sockaddr*)&this->serverAddress, sizeof(this->serverAddress));
    if (con != -1) {
        cout << "Connected to server " << endl;
    }
}

void Client::sendMessToServer(string message)
{
    send(this->clientSocket, message.c_str(), message.length(), 0);
}

Client::~Client()
{
    close(this->clientSocket);
}
