#include <stdio.h>
#include <stdlib.h>
#include <sys/sysctl.h>

void print_kernal_version(void){
int name[2] = {CTL_KERN, KERN_OSRELEASE};
    char *osrelease = NULL;
    size_t osrelease_len = 0;

    if (sysctl(name, 2, NULL, &osrelease_len, NULL, 0) == -1) {
        perror("sysctl");
    }

    osrelease = malloc(osrelease_len);

    if (osrelease == NULL) {
        perror("malloc");
    }

    if (sysctl(name, 2, osrelease, &osrelease_len, NULL, 0) == -1) {
        perror("sysctl");
    }

 

    printf("Kernel Version: %s\n", osrelease);

    free(osrelease);
}

