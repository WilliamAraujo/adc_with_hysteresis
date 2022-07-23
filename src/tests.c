#include "tests.h"

#define MIN_ADC_VALUE     0
#define MAX_ADC_VALUE     100
#define ADC_LEVEL_0       0
#define ADC_LEVEL_1       1
#define ADC_LEVEL_2       2
#define ADC_LEVEL_3       3
#define ADC_LEVEL_4       4
#define UPPER_THRESHOLD_1 15
#define UPPER_THRESHOLD_2 40
#define UPPER_THRESHOLD_3 65
#define UPPER_THRESHOLD_4 90
#define DOWN_THRESHOLD_1  10
#define DOWN_THRESHOLD_2  35
#define DOWN_THRESHOLD_3  60
#define DOWN_THRESHOLD_4  85

void setUp(void)
{
  /* This is run before EACH TEST */
}

void tearDown(void)
{
}

void test_level_up_0_to_100(){
    for(int adc_value=MIN_ADC_VALUE; adc_value<=MAX_ADC_VALUE; adc_value++){
        if(adc_value < UPPER_THRESHOLD_1){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_0);
        }
        else if(adc_value < UPPER_THRESHOLD_2){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_1);
        }
        else if(adc_value < UPPER_THRESHOLD_3){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_2);
        }
        else if(adc_value < UPPER_THRESHOLD_4){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_3);
        }
        else if(adc_value <= MAX_ADC_VALUE){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_4);
        }
    }
}

void test_level_down(){
    for(int adc_value=MAX_ADC_VALUE; adc_value >= MIN_ADC_VALUE; adc_value--){
        if(adc_value > DOWN_THRESHOLD_4){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_4);
        }
        else if(adc_value > DOWN_THRESHOLD_3){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_3);
        }
        else if(adc_value > DOWN_THRESHOLD_2){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_2);
        }
        else if(adc_value > DOWN_THRESHOLD_1){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_1);
        }
        else if(adc_value <= DOWN_THRESHOLD_1){
            TEST_ASSERT_EQUAL(adc_hysteresis(adc_value), ADC_LEVEL_0);
        }  
    } 
}

void test_level_mix(){
    int adc_value_array_mix[10] = {50, 8, 50, 8, 99, 32, 99, 32, 1, 42};
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[0]), ADC_LEVEL_2);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[1]), ADC_LEVEL_0);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[2]), ADC_LEVEL_2);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[3]), ADC_LEVEL_0);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[4]), ADC_LEVEL_4);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[5]), ADC_LEVEL_1);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[6]), ADC_LEVEL_4);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[7]), ADC_LEVEL_1);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[8]), ADC_LEVEL_0);
    TEST_ASSERT_EQUAL(adc_hysteresis(adc_value_array_mix[9]), ADC_LEVEL_2);
}

void test_main(void){
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
    /* Run Test functions */
    RUN_TEST(test_level_up_0_to_100);
    RUN_TEST(test_level_down);
    RUN_TEST(test_level_mix);
    /* Close the Unity Test Framework */
    UNITY_END();
}