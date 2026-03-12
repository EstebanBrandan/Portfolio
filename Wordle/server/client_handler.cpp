#include "client_handler.h"

ClientHandler::ClientHandler(int id, int socket) : 
    client_id(id),
    socket_fd(socket),
    handler_thread(&ClientHandler::handle_client, this) {};

void ClientHandler::handle_client() {
    std::cout << "Handling client " << client_id << std::endl;
    char buffer[1024];
    std::string message;
    ssize_t bytes_received = 0;
    bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0);
    message = std::string(buffer, bytes_received);

    std::cout << "Received from client " << client_id << ": " << message << "." << std::endl;
    // Handle client connection here
};

void ClientHandler::join() {
    close(socket_fd);
    handler_thread.join();
}