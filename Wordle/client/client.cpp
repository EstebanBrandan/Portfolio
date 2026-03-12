#include "client.h"

Client::Client() {
    self = this;
    client_socket = -1;
}

Client* Client::self = nullptr;

void Client::connect_to_server() {
    struct addrinfo hints;
    struct addrinfo *result, *ptr;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    getaddrinfo("localhost", "8080", &hints, &result);
    std::cout << "Connecting to server..." << std::endl;
    for (ptr = result; ptr; ptr = ptr->ai_next) {
        client_socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (client_socket != -1) {
            break;
        }
    }
    if (!ptr)
        throw std::runtime_error("Could not create socket");

    connect(client_socket, ptr->ai_addr, ptr->ai_addrlen);
}

void Client::start_game() {
    std::cout << "Starting game..." << std::endl;
    std::string message;
    std::cout << "Enter a message to send to the server: ";
    std::cin >> message;
    send(client_socket, message.c_str(), message.size(), 0);
    char buffer[1024];
    ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    std::cout << "Received from server: " << std::string(buffer, bytes_received) << std::endl;
}

void Client::disconnect_from_server() {
    std::cout << "Disconnecting from server..." << std::endl;
    close(client_socket);
}

void Client::end_client(int signal) {
    std::cout << "Shutting down client..." << std::endl;
    if (self) {
        self->disconnect_from_server();
    }
    exit(0);
}