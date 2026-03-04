#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include <iostream>

class Server {
private:
    int server_socket;
    static Server* self;

public:
    Server();
    void start();
    void stop();
    static void end_server(int signal);

};