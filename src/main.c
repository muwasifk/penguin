#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <assert.h>
#include <sys/utsname.h> 

#include "components/colours.h"
#include "components/ascii.h"

#include "components/unix/inc.h"

void print_centered(char* text) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // get terminal size
    int text_length = strlen(text);
    int padding = (w.ws_col - text_length) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s\n", text);
}

int main(int argc, char *argv[])
{
struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    int rows = ws.ws_row;
    int cols = ws.ws_col;

    printf("Terminal size: %dx%d\n", cols, rows);

      for (int i = 0; i < 5; i ++){
        print_centered(centrepenguin[i]);
      }

    struct utsname uname_pointer;

    uname(&uname_pointer);

    print_colours();


    char *username; username = getenv("USER"); 
    char *nodename; nodename = uname_pointer.nodename; 

    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }

    print_kernal_version();
    print_os(); 
    
    printf(BOLD(MAGENTA) "\n(local) " RESET MAGENTA "%s@%s\n" RESET, username, nodename);
    printf(BOLD(MAGENTA) "(OS) " RESET MAGENTA "%s %s %s\n" RESET, uname_pointer.sysname, uname_pointer.release, uname_pointer.machine);
    printf(BOLD(MAGENTA) "(kernel) " RESET MAGENTA "%s\n" RESET, uname_pointer.version);
    printf(BOLD(MAGENTA) "(shell) " RESET MAGENTA "%s\n" RESET, getenv("SHELL"));

    print_uptime();
    print_disk_space();
    print_cpu_name();
    print_computer_name();

    
    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }

    return 0;

}
