#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include <iostream>

class Client {
private:
    int client_socket;
    static Client* self;
public:
    Client();
    void connect_to_server();
    void disconnect_from_server();
    static void end_client(int signal);
};