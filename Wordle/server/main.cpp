#include <csignal>
#include "server.h"

int main() {
    Server server;
    std::signal(SIGINT, Server::end_server);
    server.start();
    server.stop();
    return 0;
}