#include <sys/statvfs.h>
#include <stdio.h>

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
