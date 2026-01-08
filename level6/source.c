#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n() { return system("/bin/cat /home/user/level7/.pass"); }

int m() { return puts("Nope"); }

int main(int argc, char **argv) {
  char *a = malloc(64);
  int (**b)() = malloc(4);
  *b = m;
  strcpy(a, argv[1]);
  return (*b)();
}
