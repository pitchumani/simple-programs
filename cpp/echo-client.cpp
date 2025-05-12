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

    while(1) {
        // Receive data from the server
        char buffer_client[256];
        memset(buffer_client, 0, sizeof(buffer_client));
        int bytesRead = recv(client_socket, buffer_client, sizeof(buffer_client) - 1, 0);
        if (bytesRead < 0) {
            error("Client: recv failed");
        }
        std::cout << "Client: received: " << buffer_client << std::endl;
        std::string user_message;
        std::cout << "Enter a message to send: ";
        std::cin >> user_message;
        if (user_message == std::string("quit"))
            break;
    }

    // Close the socket
    close(client_socket);
    std::cout << "Client: connection closed" << std::endl;
}

int main() {
    runClient();
    return 0;
}

