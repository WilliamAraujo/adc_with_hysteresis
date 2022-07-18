#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>
#include "log.h"
#include "tests.h"
#include "adc_hysteresis.h"
#include "unity.h"

#define test_ok     "TEST_OK"
#define test_fail   "TEST_FAILED"

// -----------------------------------------------------------------------------
// usint unity
// -----------------------------------------------------------------------------
void test_level_up_to_15(void)
{
    TEST_ASSERT_EQUAL(0, adc_hysteresis(10));    
}


void check(bool condiction, char *message, ...){
    if(condiction){
        log_success("[%s] %s\n", message, test_ok);
    }
    else{
        log_error("[%s]\n", test_fail);
    }
}

void test_level1(unsigned int value){
    printf("[%s] %d value\n", (value < 10) ? test_ok : test_fail, value);
    check(value < 10, "test_level1");   
}

void test_level_up(){
    bool status = true;
    unsigned int adc_value = 0;
    for(adc_value=0; adc_value<100; adc_value++){
        if(adc_value < 15 && status == true){
            status = (adc_hysteresis(adc_value) == 0) ? true : false;
        }
        else if(adc_value < 40 && status == true){
            status = status && (adc_hysteresis(adc_value) == 1);
        }
        else if(adc_value < 65 && status == true){
            status = status && (adc_hysteresis(adc_value) == 2);
        }
        else if(adc_value < 90 && status == true){
            status = status && (adc_hysteresis(adc_value) == 3);
        }
        else if(adc_value <= 100 && status == true){
            status = status && (adc_hysteresis(adc_value) == 4);
        }  
    }
    printf("[%s] 0 to %d\n", (status == true) ? test_ok : test_fail, adc_value);
}

void test_level_dow(){
    bool status = true;
    unsigned int adc_value = 0;
    for(adc_value=100; adc_value>=1; adc_value--){
        if(adc_value > 85 && status == true){
            status = (adc_hysteresis(adc_value) == 4) ? true : false;
        }
        else if(adc_value > 60 && status == true){
            status = status && (adc_hysteresis(adc_value) == 3);
        }
        else if(adc_value > 35 && status == true){
            status = status && (adc_hysteresis(adc_value) == 2);
        }
        else if(adc_value > 10 && status == true){
            status = status && (adc_hysteresis(adc_value) == 1);
        }
        else if(adc_value <= 10 && status == true){
            status = status && (adc_hysteresis(adc_value) == 0);
        }  
    }
    printf("[%s] 100 to %d\n", (status == true) ? test_ok : test_fail, adc_value);
}

void test_level_mix(){
    bool status = true;
    u_int16_t adc_value_array_mix[10] = {50, 8, 50, 8, 99, 32, 99, 32, 1, 42};
    status = status && (adc_hysteresis(adc_value_array_mix[0]) == 2) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[1]) == 0) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[2]) == 2) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[3]) == 0) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[4]) == 4) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[5]) == 1) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[6]) == 4) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[7]) == 1) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[8]) == 0) ? true : false;
    status = status && (adc_hysteresis(adc_value_array_mix[9]) == 2) ? true : false;
    printf("[%s] mix\n", (status == true) ? test_ok : test_fail);
}