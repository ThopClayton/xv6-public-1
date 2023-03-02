#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
    printf(1, "The current nice value is the default, which is:\n%d\n", nice(0));
    printf(1, "This is the value after incrementing by 15:\n%d\n", nice(15));
    printf(1, "To prove that the nice value is being recorded,\nthis is the value after incrementing by 15 again:\n%d\n", nice(15));
    printf(1, "This is the value after incrementing by 200:\n%d\n", nice(200));
    printf(1, "This is the value after incrementing by -999:\n%d\n", nice(-999));
    exit();
}