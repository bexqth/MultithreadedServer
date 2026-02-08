#include <iostream>
#include "client.h"
#include <string>

using namespace std;

int main() {
    Client client;
    bool connected = client.connectToServer();
    
    if (connected) {
        cout << "How much to take from storage (type 'end' to quit): " << endl;
        while(true) {
            client.handleUserInput();
        }
    }
    return 0;
}
