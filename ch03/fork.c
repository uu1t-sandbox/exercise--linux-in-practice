#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void child() {
  printf("I'm child! mypid is %d.\n", getpid());
  exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c) {
  printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(),
         pid_c);
  exit(EXIT_SUCCESS);
}

int main(void) {
  pid_t ret = fork();
  if (ret == -1) {
    err(EXIT_FAILURE, "fork(2)");
  } else if (ret == 0) {
    child();
  } else {
    parent(ret);
  }

  err(EXIT_FAILURE, "unreachable");
}
