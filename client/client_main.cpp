#include <iostream>
#include "client.h"
#include <string>

using namespace std;

int main() {
    Client client;
    bool connected = client.connectToServer();
    
    if (connected) {
        while(true) {
            cout << "How much to take from storage (type 'end' to quit): " << endl;
            client.handleUserInput();
        }
    }
    return 0;
}
