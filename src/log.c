#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include "log.h"

bool time_prefix = false;

void log_use_time_prefix(bool toggle)
{
    time_prefix = toggle;
}

void log_info(char *format_string, ...)
{
    va_list args1;
    va_start(args1, format_string);
    va_list args2;
    va_copy(args2, args1);
    char buf[1 + vsnprintf(NULL, 0, format_string, args1)];
    va_end(args1);
    vsnprintf(buf, sizeof buf, format_string, args2);
    va_end(args2);

    if (time_prefix)
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("%d:%d:%d \033[0m\033[1;34m[INFO]\033[0m %s", tm.tm_hour, tm.tm_min, tm.tm_sec, buf);
    }
    else
    {
        printf("\033[0m\033[1;34m[INFO]\033[0m %s", buf);
    }
}

void log_error(char *format_string, ...)
{
    va_list args1;
    va_start(args1, format_string);
    va_list args2;
    va_copy(args2, args1);
    char buf[1 + vsnprintf(NULL, 0, format_string, args1)];
    va_end(args1);
    vsnprintf(buf, sizeof buf, format_string, args2);
    va_end(args2);
    if (time_prefix)
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("%d:%d:%d \033[0m\033[1;31m[FAIL]\033[0m %s", tm.tm_hour, tm.tm_min, tm.tm_sec, buf);
    }
    else
    {
        printf("\033[0m\033[1;31m[FAIL]\033[0m %s", buf);
    }
}

void log_success(char *format_string, ...)
{
    va_list args1;
    va_start(args1, format_string);
    va_list args2;
    va_copy(args2, args1);
    char buf[1 + vsnprintf(NULL, 0, format_string, args1)];
    va_end(args1);
    vsnprintf(buf, sizeof buf, format_string, args2);
    va_end(args2);
    if (time_prefix)
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("%d:%d:%d \033[0m\033[1;32m[PASS]\033[0m %s", tm.tm_hour, tm.tm_min, tm.tm_sec, buf);
    }
    else
    {
        printf("\033[0m\033[1;32m[PASS]\033[0m %s", buf);
    }
}

void log_warning(char *format_string, ...)
{
    va_list args1;
    va_start(args1, format_string);
    va_list args2;
    va_copy(args2, args1);
    char buf[1 + vsnprintf(NULL, 0, format_string, args1)];
    va_end(args1);
    vsnprintf(buf, sizeof buf, format_string, args2);
    va_end(args2);
    if (time_prefix)
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("%d:%d:%d \033[0m\033[1;33m[WARN]\033[0m %s", tm.tm_hour, tm.tm_min, tm.tm_sec, buf);
    }
    else
    {
        printf("\033[0m\033[1;33m[WARN]\033[0m %s", buf);
    }
}