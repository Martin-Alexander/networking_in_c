#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

  // Create a socket
  int network_socket_id = socket(AF_INET, SOCK_STREAM, 0);

  // Specift an address for the socket
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  int connection_status = connect(network_socket_id, (struct sockaddr*) &server_address, sizeof(server_address));
  // Check for connection error
  if (connection_status) {
    printf("ERROR\n\n");
  }

  // Recieve data from server
  char server_response[256];
  recv(network_socket_id, &server_response, sizeof(server_response), 0);

  // Print data from server
  printf("Response: %s\n\n", server_response);

  // Close socket
  close(network_socket_id);

  return 0;
}