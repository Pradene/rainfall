#include <stdio.h>
#include <stdlib.h>

void v(void) {
  char buf[520];

  fgets(buf, 512, stdin);
  int size = printf(buf);
  if (size == 64) {
    fwrite("Wait what?!\n", 1, 0xc, stdout);
    system("/bin/sh");
  }

  return;
}

int main(void) {
  v();
  return 0;
}
