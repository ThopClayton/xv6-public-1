// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

#define N  500000000

int prime() { 
   int prime = 1;
   

   for(int num = 2; num < N; num++) {
      if((N % num) == 0) {
         prime = 0;
      }
      if (num % 100000000 == 0) {
        printf(1, "up to %d\n", num);
      }
   }

   if (prime == 1)
      printf(1, "%d is prime number.\n", N);
   else
      printf(1, "%d is not a prime number.\n", N);
   return 0;
}

void
forktest(void)
{
  int pid;
  nice(999);
  pid = fork();
  if(pid < 0) { //fork failed
    printf(1, "fork failed\n");
    exit();
  }
  if(pid == 0) { //child process
    nice(-999);
    printf(1, "I'm the child!\n");
    printf(1, "I have %d tickets!\n", 50+nice(0));
    prime();
    exit();
  }
  if(pid != wait()){
    printf(1, "wait() failed!\n");
    exit();
  }
  printf(1, "I'm the parent!\n");
  printf(1, "I have %d tickets!\n", 50+nice(0));
  prime();

}

int
main(void)
{
  printf(1, "In this test, the parent waits while holding 150 tickets,\nwhile the child only gets 1.\n");
  forktest();
  exit();
}
