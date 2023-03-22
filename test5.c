#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    printf(1, "This is a simple test.\nA new system call named \"evil\" has been created that sets the tickets\nfor the current process to zero.");
    printf(1, " After this print statement finishes,\nthat system call will be used, and this message will repeat,\nbut not to completeion since there are no tickets.\n");
    printf(1, "This simply shows that the number a process with no tickets\n(which is impossible without the evil system call)\nwould never win, and therefore my");
    printf(1, " implementation is correct.\n-----------------------------\n");
    evil();
    printf(1, "This is a simple test.\nA new system call named \"evil\" has been created that sets the tickets\nfor the current process to zero.");
    printf(1, " After this print statement finishes,\nthat system call will be used, and this message will repeat,\nbut not to completeion since there are no tickets.\n");
    printf(1, "This simply shows that the number a process with no tickets\n(which is impossible without the evil system call)\nwould never win, and therefore my");
    printf(1, " implementation is correct.\n-----------------------------\n");
    exit();
}