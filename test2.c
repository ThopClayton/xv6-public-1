#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
    for (int i=0; i<15; i++)
        printf(1, "%d\n", random());
    exit();
}