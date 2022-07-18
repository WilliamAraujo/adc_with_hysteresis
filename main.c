#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

int main(int argc, char const *argv[])
{    
    printf(".......... Starting tests ..........\n");
    test_level_up();
    test_level_dow();
    test_level_mix();
    test_level1(8);
    return 0;
}