#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "components/colours.h"

// https://sourceforge.net/projects/predef/
#if defined(__unix__) || defined(__unix) || defined(__APPLE__) || defined(__MACH__)
#include "unix.h"
#endif

#if defined(__APPLE__) || defined(__MACH__)
#include "apple.h"
#elif defined(__linux__)
#include "linux.h"
elif defined(_WIN32) || defined(_WIN64)
#include "windows.h"
#endif


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
