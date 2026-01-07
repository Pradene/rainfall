#include <stdio.h>
#include <string.h>

void p(void) {
  unsigned int s;
  char buf[76];

  fflush(stdout);
  gets(buf);
  if ((s & 0xb0000000) == 0xb0000000) {
    printf("(%p)\n", s);
    exit(1);
  }
  puts(buf);
  strdup(buf);
  return;
}

int main(void) {
  p();
  return (0);
}
