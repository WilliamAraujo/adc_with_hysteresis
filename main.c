#include "log.h"
#include "unity.h"
#include "tests.h"


int main(int argc, char const *argv[])
{
    log_info("%s\n", ".......... Starting Unity Tests ..........");
    test_main();
    return 0;
}
