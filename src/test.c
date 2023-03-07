#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LEN 1000
#define MAX_GPU_NAME_LEN 100

int main() {
    char command[MAX_COMMAND_LEN];
    char gpuName[MAX_GPU_NAME_LEN];
    FILE *fp;

    // Construct the command to retrieve the GPU name
    snprintf(command, MAX_COMMAND_LEN, "system_profiler SPDisplaysDataType | grep Chipset");

    // Open a pipe to execute the command and retrieve its output
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to execute command\n");
        exit(1);
    }

    // Read the output of the command and extract the GPU name
    char output[MAX_COMMAND_LEN];
    fgets(output, MAX_COMMAND_LEN, fp);
    sscanf(output, "      Chipset Model: %s", gpuName);

    // Close the pipe and print the GPU name
    pclose(fp);
    printf("GPU name: %s\n", gpuName);

    return 0;
}
