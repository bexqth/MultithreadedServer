#include <iostream>
#include "client.h"
#include <string>

using namespace std;

int main() {
    Client client;
    bool connected = client.connectToServer();
    
    if (connected) {
        while(true) {
            client.handleUserInput();
        }
    }
    return 0;
}
