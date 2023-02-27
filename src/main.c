#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/utsname.h> 
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/sysctl.h>
#include <CoreGraphics/CoreGraphics.h>

#include "components/colours.h"


char* apple = "\n"
                  "                      :-==\n"                                
                  "                   .-++++-\n"                                
                  "                  :+++++=\n"                                 
                  "                 .++++=-\n"                                  
                  "                 -+=-:\n"                                    
                  "     .:==++++==-::..:-==+++++=-:\n"                          
                  "   .=+++++++++++++++++++++++++++=-\n"                        
                  "  :=============================-.\n"                        
                  " :=============================.\n"                          
                  " =============================.\n"                           
                  ".++++++++++++++++++++++++++++=\n"                            
                  ".+++++++++++++++++++++++++++++\n"                            
                  " *****************************-\n"                           
                  " +*****************************=\n"                          
                  " .*******************************=.\n"                       
                  "  :*******************************+.\n"                      
                  "   -*****************************+.\n"                       
                  "    :+++++++++++++++++++++++++++=\n"                        
                  "      -------------------------:\n"                          
                  "       .--------:::::--------:\n"                            
                  "          ....          ....";


char* penguin =   "   _\n"
                  " ('v')\n"
                  "//-=-\\\\\n"
                  "(\\_=_/)\n"
                  " ^^ ^^";

void print_colours() {
    printf("\033[0;30m██████\033[0m\033[0;31m██████\033[0m\033[0;32m██████\033[0m\033[0;33m██████\033[0m\033[0;34m██████\033[0m\033[0;35m██████\033[0m\033[0;36m██████\033[0m\033[0;37m██████\033[0m\n");
    printf("\033[0;30m██████\033[0m\033[0;31m██████\033[0m\033[0;32m██████\033[0m\033[0;33m██████\033[0m\033[0;34m██████\033[0m\033[0;35m██████\033[0m\033[0;36m██████\033[0m\033[0;37m██████\033[0m\n");
}

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

void print_resolutions(void){
    uint32_t count;
    CGGetActiveDisplayList(0, NULL, &count);

    CGDirectDisplayID displays[count];
    CGGetActiveDisplayList(count, displays, &count);

    for (uint32_t i = 0; i < count; i++) {
        uint32_t width = CGDisplayPixelsWide(displays[i]);
        uint32_t height = CGDisplayPixelsHigh(displays[i]);

        printf("Display %d: %ux%u\n", i+1, width, height);
    }
}

int main(int argc, char *argv[])
{
    struct utsname uname_pointer;

    uname(&uname_pointer);

    printf(BOLD(BLUE)"%s\n"RESET, penguin);
    print_colours();


    char *username; username = getenv("USER"); 
    char *nodename; nodename = uname_pointer.nodename; 

    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }

   int name[2] = {CTL_KERN, KERN_OSRELEASE};
    char *osrelease = NULL;
    size_t osrelease_len = 0;

    if (sysctl(name, 2, NULL, &osrelease_len, NULL, 0) == -1) {
        perror("sysctl");
        return 1;
    }

    osrelease = malloc(osrelease_len);

    if (osrelease == NULL) {
        perror("malloc");
        return 1;
    }

    if (sysctl(name, 2, osrelease, &osrelease_len, NULL, 0) == -1) {
        perror("sysctl");
        return 1;
    }

    printf("Kernel Version: %s\n", osrelease);

    free(osrelease);
    
    printf(BOLD(MAGENTA) "\n(local) " RESET MAGENTA "%s@%s\n" RESET, username, nodename);
    printf(BOLD(MAGENTA) "(OS) " RESET MAGENTA "%s %s %s\n" RESET, uname_pointer.sysname, uname_pointer.release, uname_pointer.machine);
    printf(BOLD(MAGENTA) "(kernel) " RESET MAGENTA "%s\n" RESET, uname_pointer.version);
    printf(BOLD(MAGENTA) "(shell) " RESET MAGENTA "%s\n" RESET, getenv("SHELL"));

    print_uptime();
    print_disk_space();
    print_cpu_name();
    print_computer_name();
    print_resolutions();

    
    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }

    return 0;

}
