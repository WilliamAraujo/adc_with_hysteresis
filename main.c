#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "unity.h"

int main(int argc, char const *argv[])
{
    printf(".......... Starting UNITY tests ..........\n");
    test_main();
    printf(".......... Starting CUSTOM tests ..........\n");
    test_level_up();
    test_level_dow();
    test_level_mix();
    test_level1(8);
    return 0;
}