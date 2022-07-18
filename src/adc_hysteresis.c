#define levels      4
#define MIN_VALUE   0
#define MAX_VALUE   100
#define level_1     {10, 15, 1}
#define level_2     {35, 40, 2}
#define level_3     {60, 65, 3}
#define level_4     {85, 90, 4}
#define start_level levels-1

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
    unsigned int level = 0;
    for(unsigned int i = 0; i < levels; i++){
        if(input_percent >= thresholds[i][HIGH]){
            level = thresholds[i][LEVEL];
        }
    }
    return level;
}

unsigned int level_down(unsigned int input_percent){
    unsigned int level = 0;
    for(unsigned int i = 0; i < levels; i++){
        if(input_percent > thresholds[start_level-i][LOW]){
            return thresholds[start_level-i][LEVEL];
        }
    }
    return level;
}

unsigned int adc_hysteresis(unsigned int input_percent){
    unsigned int level = 0;
    static unsigned int _input_precent = 0;

    level = (input_percent >= _input_precent) ? level_up(input_percent) : level_down(input_percent);

    _input_precent = input_percent;

    return level;
}