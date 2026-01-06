#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (atoi(argv[1]) == 423) {
    char *cmd[] = {"/bin/bash", NULL};

    uid_t uid = geteuid();
    gid_t gid = getegid();

    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);

    execv(cmd[0], cmd);
  } else {
    fwrite("No !\n", 1, 5, stderr);
  }

  return (0);
}
