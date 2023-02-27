#ifndef UNIX_H
#define UNIX_H

#include <sys/utsname.h> 
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/sysctl.h>


struct timespec get_uptime()
{
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

void print_disk_space(void) {
    // Get disk space
    struct statvfs vfs;
    if (statvfs("/", &vfs) == -1) {
        perror("statvfs");
        return;
    }
    unsigned long long block_size = vfs.f_frsize;
    unsigned long long total_blocks = vfs.f_blocks;
    unsigned long long free_blocks = vfs.f_bfree;
    unsigned long long total_space = block_size * total_blocks;
    unsigned long long free_space = block_size * free_blocks;
    printf(BOLD(MAGENTA) "(disk) " RESET MAGENTA "%.2f GB free of %.2f GB\n"RESET, (double)free_space / 1e9, (double)total_space / 1e9);
}

void print_cpu_name(void){
    char cpu_name[256];
    size_t size = sizeof(cpu_name);
    int error = sysctlbyname("machdep.cpu.brand_string", &cpu_name, &size, NULL, 0);
    
    printf("CPU name: %s\n", cpu_name);
}

void print_computer_name(void){
    size_t len;
    char *model;

    sysctlbyname("hw.model", NULL, &len, NULL, 0);

    model = malloc(len);

    if (sysctlbyname("hw.model", model, &len, NULL, 0) == -1) {
        perror("sysctlbyname");
    }

    printf("Model: %s\n", model);
    
    free(model);
}


#endif /* UNIX_H */
