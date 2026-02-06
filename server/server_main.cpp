#include <iostream>
#include "server.h"

int main() {
    Server server;
    server.startServer();
    server.handleClient();
    return 0;
}
