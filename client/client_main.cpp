#include <iostream>
#include "client.h"
#include <string>

using namespace std;

int main() {
    Client client;
    client.connectToServer();
    string userInput;

    while(userInput != "end") {
        cout << "Enter message to be sent (type 'end' to quit): " << endl;
        
        getline(cin, userInput);
        
        if(userInput == "end") {
            break;
        }

        client.sendMessToServer(userInput);
    }

    return 0;
}
