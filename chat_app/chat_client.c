#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {
  while(1) {

    // Create a socket
    int network_socket_id = socket(AF_INET, SOCK_STREAM, 0);

    // Specift an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket_id, (struct sockaddr*) &server_address, sizeof(server_address));
    // Check for connection error
    if (connection_status) {
      printf("ERROR\n\n");
    }

    char message[256];
    fgets(message, sizeof(message), stdin);
    send(network_socket_id, &message, sizeof(message), 0);

    // Close socket
    close(network_socket_id);

  }
  return 0;
}