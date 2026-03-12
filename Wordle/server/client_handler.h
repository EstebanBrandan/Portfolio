#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class ClientHandler {
    std::thread handler_thread;
    int client_id;
    int socket_fd;

    void handle_client();
public:
    ClientHandler(int id, int socket);
    void join();
};