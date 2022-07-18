#ifndef ADC_HYSTERESIS_H
#define ADC_HYSTERESIS_H

/**
 * @brief Read the ADC value and return the hysteresis level.
 * 
 * @param input_percent analog input (0-100).
 * @return discrete level (0-4).
 */
unsigned int adc_hysteresis(unsigned int input_percent);

#endif // ADC_HYSTERESIS_H