#include "server.h"

Server::Server() {
    self = this;
    server_socket = -1;
    struct addrinfo hints;
    struct addrinfo *result, *ptr;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    getaddrinfo("localhost", "8080", &hints, &result);
    std::cout << "Setting up server..." << std::endl;
    for (ptr = result; ptr; ptr = ptr->ai_next) {
        server_socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (server_socket != -1) {
            break;
        }
    }
    if (!ptr)
        throw std::runtime_error("Could not create socket");

    bind(server_socket, ptr->ai_addr, ptr->ai_addrlen);
    listen(server_socket, 1);
}

Server* Server::self = nullptr;

void Server::start() {
    while (true) {
        std::cout << "Waiting for client connection..." << std::endl;
        int clientfd = accept(server_socket, NULL, NULL);
        if (clientfd == -1) {
            continue;
        }
        std::cout << "Client connected!" << std::endl;
        // Handle client connection here
        close(clientfd);
    }
}

void Server::stop() {
    std::cout << "Stopping server..." << std::endl;
    close(server_socket);
}

void Server::end_server(int signal) {
    std::cout << "Shutting down server..." << std::endl;
    if (self) {
        self->stop();
    }
    exit(0);
}