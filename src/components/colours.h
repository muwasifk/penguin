#include <stdio.h>
#include <string.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#define BOLD(color) "\x1b[1m" color

void print_colours() {
    printf("\033[0;30m██\033[0m\033[0;31m██\033[0m\033[0;32m██\033[0m\033[0;33m██\033[0m\033[0;34m██\033[0m\033[0;35m██\033[0m\033[0;36m██\033[0m\033[0;37m██\033[0m\n");
    printf("\033[0;30m██████\033[0m\033[0;31m██████\033[0m\033[0;32m██████\033[0m\033[0;33m██████\033[0m\033[0;34m██████\033[0m\033[0;35m██████\033[0m\033[0;36m██████\033[0m\033[0;37m██████\033[0m\n");
}



