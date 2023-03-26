#include <stdio.h>
#include <sys/sysctl.h> 

void print_cpu_name(void){
    char cpu_name[256];
    size_t size = sizeof(cpu_name);
    sysctlbyname("machdep.cpu.brand_string", &cpu_name, &size, NULL, 0);
    
    printf("CPU name: %s\n", cpu_name);
}