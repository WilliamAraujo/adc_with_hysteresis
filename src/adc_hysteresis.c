#define levels      4
#define MIN_VALUE   0
#define MAX_VALUE   100
#define level_1     {10, 15, 1}
#define level_2     {35, 40, 2}
#define level_3     {60, 65, 3}
#define level_4     {85, 90, 4}
#define level_range levels-1

typedef enum {
    LOW,
    HIGH,
    LEVEL
}threshold_t;

const unsigned int thresholds[levels][levels-1] = {
    level_1,
    level_2,
    level_3,
    level_4
};

unsigned int level_up(unsigned int input_percent){
    for(int i = level_range; i >= 0; i--){
        if(input_percent >= thresholds[i][HIGH]){
            return thresholds[i][LEVEL];
        }
    }
    return 0;
}

unsigned int level_down(unsigned int input_percent){
    for(int i = 0; i <= level_range; i++){
        if(input_percent > thresholds[level_range-i][LOW]){
            return thresholds[level_range-i][LEVEL];
        }
    }
    return 0;
}

unsigned int adc_hysteresis(unsigned int input_percent){
    unsigned int level = 0;
    static unsigned int _input_percent = 0;

    level = (input_percent >= _input_percent) ? level_up(input_percent) : level_down(input_percent);

    _input_percent = input_percent;

    return level;
}