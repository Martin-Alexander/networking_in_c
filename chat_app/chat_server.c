#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

  // Create network socket and buffer
  int server_socket_id = socket(AF_INET, SOCK_STREAM, 0);

  // Setup stuct containing port and IP address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Bind socket to port and IP address
  bind(server_socket_id, (struct sockaddr*) &server_address, sizeof(server_address));

  listen(server_socket_id, 5);

  while(1) {
    char incoming_message[256] = "";
    int client_socket_id = accept(server_socket_id, NULL, NULL);
    recv(client_socket_id, &incoming_message, sizeof(incoming_message), 0);
    printf("Recieved: ");
    printf("%s", incoming_message);
    close(client_socket_id);
  }

  return 0;
}