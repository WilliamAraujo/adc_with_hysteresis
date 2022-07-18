#include <stdbool.h>

void log_use_time_prefix(bool toggle);

void log_info(char* message, ...);

void log_error(char* message, ...);

void log_success(char* message, ...);

void log_warning(char* message, ...);