#include <sys/utsname.h> 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include "colours.h"


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


char* penguin = "   _\n"
                  " ('v')\n"
                  "//-=-\\\\\n"
                  "(\\_=_/)\n"
                  " ^^ ^^";

void showColours() {
    printf("\033[0;30m██████\033[0m\033[0;31m██████\033[0m\033[0;32m██████\033[0m\033[0;33m██████\033[0m\033[0;34m██████\033[0m\033[0;35m██████\033[0m\033[0;36m██████\033[0m\033[0;37m██████\033[0m\n");
    printf("\033[0;30m██████\033[0m\033[0;31m██████\033[0m\033[0;32m██████\033[0m\033[0;33m██████\033[0m\033[0;34m██████\033[0m\033[0;35m██████\033[0m\033[0;36m██████\033[0m\033[0;37m██████\033[0m\n");
	
    // bold colours
    //printf("\033[1;30m██████\033[0m\033[1;31m██████\033[0m\033[1;32m██████\033[0m\033[1;33m██████\033[0m\033[1;34m██████\033[0m\033[1;35m██████\033[0m\033[1;36m██████\033[0m\033[1;37m██████\033[0m\n");
    //printf("\033[1;30m██████\033[0m\033[1;31m██████\033[0m\033[1;32m██████\033[0m\033[1;33m██████\033[0m\033[1;34m██████\033[0m\033[1;35m██████\033[0m\033[1;36m██████\033[0m\033[1;37m██████\033[0m\n");
}

void print_uptime(void) {
    // Get system uptime
    struct timeval now;
    if (gettimeofday(&now, NULL) == -1) {
        perror("gettimeofday");
        return;
    }
    unsigned long long total_seconds = now.tv_sec;
    int days = total_seconds / 86400;
    int hours = (total_seconds / 3600) % 24;
    int minutes = (total_seconds / 60) % 60;
    int seconds = total_seconds % 60;
    printf(BOLD(MAGENTA) "(uptime) " RESET MAGENTA "%d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);
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
    printf(BOLD(MAGENTA) "(disk) " RESET MAGENTA "%.2f GB free of %.2f GB\n", (double)free_space / 1e9, (double)total_space / 1e9);
}

int main(int argc, char *argv[])
{
    struct utsname uname_pointer;

    uname(&uname_pointer);

    puts(penguin);


    char *username; username = getenv("USER"); 
    char *nodename; nodename = uname_pointer.nodename; 

    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }
    
    printf(BOLD(MAGENTA) "\n(local) " RESET MAGENTA "%s@%s\n" RESET, username, nodename);
    printf(BOLD(MAGENTA) "(OS) " RESET MAGENTA "%s %s %s\n" RESET, uname_pointer.sysname, uname_pointer.release, uname_pointer.machine);
    printf(BOLD(MAGENTA) "(Kernel) " RESET MAGENTA "%s\n" RESET, uname_pointer.version);
    printf(BOLD(MAGENTA) "(Shell) " RESET MAGENTA "%s\n" RESET, getenv("SHELL"));

    print_uptime();
    print_disk_space();

    showColours();
    
    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }

    return 0;

}
