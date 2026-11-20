#include <test.h>
#include "logger.h"

void to_test(){
    Log(TRACE, "xxx");
    int a = 11;
    Log(TRACE, "{} nb", 11);
    logger.all_log(__FILE__, __LINE__, TRACE, "%d nb", 12);

    printf("nice nice try\n");
    Log(TRACE, "{} nb {} {}", "xxxxx", 'c', 2000);
    
}