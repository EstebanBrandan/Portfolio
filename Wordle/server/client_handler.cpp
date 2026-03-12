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
    
    std::stringstream response;
    std::string misterious_word = "HELLO";
    std::transform(message.begin(), message.end(), message.begin(), ::toupper);
    if (message == misterious_word) {
        response << "\033[32m" << misterious_word << "\033[0m";
    } else {
        int i = 0;
        for (char& c : message) {
            if (misterious_word.find(c) != std::string::npos) {
                if (misterious_word[i] == c) {
                    response << "\033[32m";
                } else {
                    response << "\033[33m";
                }
                response << c << "\033[0m";
            } else {
                response << "\033[31m" << c << "\033[0m";
            }
            i++;
        }
    }
    send(socket_fd, response.str().c_str(), response.str().size(), 0);

};

void ClientHandler::join() {
    close(socket_fd);
    handler_thread.join();
}