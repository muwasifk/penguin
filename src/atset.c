#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF 1024

int main() {
    char buffer[MAX_BUF];
    char *os_name = NULL;
    char *os_version = NULL;

    FILE *sw_vers_pipe = popen("sw_vers", "r");
    if (sw_vers_pipe == NULL) {
        fprintf(stderr, "Failed to execute sw_vers command\n");
        return 1;
    }

    while (fgets(buffer, MAX_BUF, sw_vers_pipe) != NULL) {
        if (strstr(buffer, "ProductName:") != NULL) {
            os_name = strdup(buffer + strlen("ProductName:"));
            os_name[strcspn(os_name, "\r\n")] = '\0';
        } else if (strstr(buffer, "ProductVersion:") != NULL) {
            os_version = strdup(buffer + strlen("ProductVersion:"));
            os_version[strcspn(os_version, "\r\n")] = '\0';
        }
    }

    pclose(sw_vers_pipe);

    if (os_name != NULL && os_version != NULL) {
        printf("Operating system: %s %s\n", os_name, os_version);
    } else {
        fprintf(stderr, "Failed to retrieve operating system information\n");
        return 1;
    }

    free(os_name);
    free(os_version);

    return 0;
}
