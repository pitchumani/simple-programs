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

    // receiving data from client
    char buffer[256];
    memset(buffer, 0, 256);
    int n = read(c_fd, buffer, 256);
    if (n < 0) {
        error("Server: read() failed");
    }

    std::cout << "Server: received message '" << buffer << "'" << std::endl;

    // send a response to client
    std::string response("Hello from the server");
    n = write(c_fd, response.c_str(), response.length());
    if (n < 0) {
        error("Server: write() failed");
    }
    std::cout << "Server: sent a response" << std::endl;

    // closing connections
    close(s_fd);
    close(c_fd);
}

// ----------------------------------------
// Client Code
// ----------------------------------------
void runClient() {
    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        error("Client: socket creation failed");
    }

    // Server address
    sockaddr_in server_address_client;
    server_address_client.sin_family = AF_INET;
    server_address_client.sin_addr.s_addr = inet_addr("127.0.0.1");  // Connect to localhost
    server_address_client.sin_port = htons(8080);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address_client, sizeof(server_address_client)) < 0) {
        error("Client: connect failed");
    }

    std::cout << "Client: connected to server" << std::endl;

    // Send data to the server
    std::string message = "Hello from the client!";
    send(client_socket, message.c_str(), message.length(), 0);
    std::cout << "Client: sent message: " << message << std::endl;

    // Receive data from the server
    char buffer_client[256];
    memset(buffer_client, 0, sizeof(buffer_client));
    int bytesRead = recv(client_socket, buffer_client, sizeof(buffer_client) - 1, 0);
    if (bytesRead < 0) {
        error("Client: recv failed");
    }
    std::cout << "Client: received: " << buffer_client << std::endl;

    // Close the socket
    close(client_socket);
    std::cout << "Client: connection closed" << std::endl;
}

int main() {
    // run server in a thread
    std::thread serverThread(runServer);
    std::thread clientThread(runClient);

    serverThread.join();
    clientThread.join();

    return 0;
}

