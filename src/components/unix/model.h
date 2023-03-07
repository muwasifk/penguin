#include <stdlib.h>
#include <stdio.h>
#include <sys/sysctl.h>

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