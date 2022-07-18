#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <stdarg.h>
// #include <time.h>
// #include "log.h"
#include "tests.h"
#include "unity.h"
#include "adc_hysteresis.h"

void setUp(void)
{
  /* This is run before EACH TEST */
}

void tearDown(void)
{
}

void test_level1(){
    TEST_ASSERT_EQUAL(0, adc_hysteresis(8));   
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
    TEST_ASSERT_EQUAL(status, true);
}

void test_level_down(){
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
    TEST_ASSERT_EQUAL(status, true);    
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
    TEST_ASSERT_EQUAL(status, true);
}

void test_main(void){
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
    /* Run Test functions */
    RUN_TEST(test_level_up);
    RUN_TEST(test_level_down);
    RUN_TEST(test_level_mix);    
    RUN_TEST(test_level1);
    /* Close the Unity Test Framework */
    UNITY_END();    
}