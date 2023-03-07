#include <sys/time.h>
#include <stdio.h>

struct timespec get_uptime(){
    struct timespec uptime;
    if (0 != clock_gettime(CLOCK_MONOTONIC_RAW, &uptime))
    {
        perror("uptime");
    }

    return uptime;
}


void print_uptime(void) {
    struct timespec uptime = get_uptime();
    
    int days = uptime.tv_sec / 86400; 
    int hours = ( uptime.tv_sec % 86400 ) / 3600; 
    int minutes = ( ( uptime.tv_sec % 86400 ) % 3600 ) / 60; 
    int seconds = ( ( uptime.tv_sec % 86400 ) % 3600 ) % 60; 


    printf(BOLD(MAGENTA) "(uptime) " RESET MAGENTA "%i days, %i hours, %i minutes, %i seconds\n" RESET, days, hours, minutes, seconds); 
}