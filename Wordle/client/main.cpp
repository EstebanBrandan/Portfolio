#include <csignal>
#include "client.h"

int main() {
    Client client;
    std::signal(SIGINT, Client::end_client);
    client.connect_to_server();
    client.start_game();
    client.disconnect_from_server();
    return 0;
}