#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

void error(const std::string &msg) {
    std::cerr << msg << std::endl;
    exit(1);
}

// ----------------------------------------
// Server Code
// ----------------------------------------
void runServer() {
    // server socket creation
    int s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (s_fd == -1) {
        error("Server socket creation failed");
    }
    // socket configuration
    sockaddr_in s_address;
    int s_port = 8080;
    s_address.sin_family = AF_INET;
    s_address.sin_addr.s_addr = INADDR_ANY;
    s_address.sin_port = htons(s_port);

    // binding the socket
    int res = bind(s_fd, (struct sockaddr*)&s_address, sizeof(s_address));
    if (res < 0) {
        error("Server: bind() failed");
    }

    res = listen(s_fd, 5);
    if (res < 0) {
        error("Server: listen() failed");
    }
    std::cout << "Server: listening on the port " << s_port << std::endl;

    // accept a connection
    int c_fd = accept(s_fd, NULL, NULL);
    if (c_fd == -1) {
        error("Server: accept() failed");
    }
    std::cout << "Server: connection accepted" << std::endl;

    while (1) {
        // receiving data from client
        char buffer[256];
        memset(buffer, 0, 256);
        int n = read(c_fd, buffer, 256);
        if (n < 0) {
            error("Server: read() failed");
        }

        std::cout << "Server: received message '" << buffer << "'" << std::endl;

        if (strcmp(buffer, "quit") == 0) {
            std::cout << "quitting the server as requested" << std::endl;
            break;
        }
        // send a response to client
        std::string response(">> ");
        response.append(buffer);
        n = write(c_fd, response.c_str(), response.length());
        if (n < 0) {
            error("Server: write() failed");
        }
        std::cout << "Server: sent a response" << std::endl;
    }

    // closing connections
    close(s_fd);
    close(c_fd);
}

int main() {
    runServer();
    return 0;
}

