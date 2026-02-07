#include <iostream>
#include "client.h"
#include <string>

using namespace std;

int main() {
    Client client;
    bool connected = client.connectToServer();
    string userInput;
    if (connected) {
        while(userInput != "end") {
        cout << "Enter message to be sent (type 'end' to quit): " << endl;
        
        getline(cin, userInput);
        
        if(userInput == "end") {
            break;
        }

        client.sendMessToServer(userInput);
        }
    }
    return 0;
}
