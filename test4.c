#include "types.h"
#include "stat.h"
#include "user.h"

#define N  2000000000

int prime(char * name) { 
   int prime = 1;
   

   for(int num = 2; num < N; num++) {
      if((N % num) == 0) {
         prime = 0;
      }
      if (num % 100000000 == 0) {
        printf(1, "%s: up to %d\n", name, num);
      }
   }

   if (prime == 1)
      printf(1, "%s: %d is prime number.\n", name, N);
   else
      printf(1, "%s: %d is not a prime number.\n", name, N);
   return 0;
}


void
forktest(void)
{
  int pid;

  pid = fork();
  if(pid < 0) { //fork failed
    printf(1, "fork failed\n");
    exit();
  }
  if(pid > 0) {//in parent
    nice(999);
    printf(1, "Parent %d tickets!\n", 50+nice(0));
    prime("parent");
  }

  if(pid == 0) { //child process
    pid = fork();
    if(pid < 0) { //fork failed
      printf(1, "fork failed\n");
      exit();
    } if (pid > 0) { //first child process
      printf(1, "child1: %d tickets!\n", 50+nice(0));
      prime("child1");
    } if (pid == 0) { //second child process
      nice(50);
      printf(1, "child2: %d tickets!\n", 50+nice(0));
      prime("child2");
      exit();
    }
    if(pid != wait()){
      printf(1, "wait() failed!\n");
      exit();
    }
    exit();

  }
  if(pid != wait()){
    printf(1, "wait() failed!\n");
    exit();
  }
  printf(1, "test over\n");
}

int
main(void)
{
  forktest();
  exit();
}
