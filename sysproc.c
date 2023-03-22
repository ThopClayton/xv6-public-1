#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int sys_randSeed = 5;

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// adjusts nice value
int sys_nice(void) {
  int inc;
  if(argint(0, &inc) < 0) //assign param
    return -1;
  struct proc * p = myproc();

  
  if (p->nice + inc > 100) {
    p->nice = 100;
  } else if (p->nice + inc < -49) {
    p->nice = -49;
  } else {
    p->nice = p->nice + inc;
  }

  return p->nice;
}

int sys_evil(void) {
  struct proc * p = myproc();
  p->nice = -50;
  return p->nice;
}

// returns random int value
// mostly stolen from wikipedia's xorshift article
int sys_random(void) {
  sys_randSeed ^= sys_randSeed >> 12;
  sys_randSeed ^= sys_randSeed << 25;
  sys_randSeed ^= sys_randSeed >> 27;
  return sys_randSeed; 
}