#include <stdio.h>
#include <stdlib.h>

int p(char *arg1) { return printf(arg1); }

int n() {
  char buf[520];

  fgets(buf, 512, stdin);
  int size = p(buf);

  if (size != 16930116) {
    return size;
  }

  return system("/bin/cat /home/user/level5/.pass");
}

int main() { return n(); }
