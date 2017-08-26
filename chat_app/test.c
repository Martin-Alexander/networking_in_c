#include <stdio.h>
#include <string.h>

int main() {

  while(1) {
    char input[256];
    fgets(input, sizeof(input), stdin);
    printf("%s\n", input);
  }
}