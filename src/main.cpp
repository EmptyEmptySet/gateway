#include <test.h>
#include "logger.h"

int main(){
    printf("nice try\n");
    to_test();
    Log(TRACE, "xxx");
    return 0;
}