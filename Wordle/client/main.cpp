#include <csignal>
#include "client.h"

int main() {
    Client client;
    std::signal(SIGINT, Client::end_client);
    client.connect_to_server();
    // Do something with the client
    client.disconnect_from_server();
    return 0;
}