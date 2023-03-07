#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main()
{
    char *homebrew_cmd = "brew list | wc -l";
    char *macports_cmd = "port installed | wc -l";
    FILE *fp;
    char buf[BUFSIZE];
    int homebrew_count = 0, macports_count = 0;

    // Check for Homebrew packages
    fp = popen(homebrew_cmd, "r");
    if (fp != NULL) {
        size_t nread;
        while ((nread = fread(buf, 1, BUFSIZE, fp)) > 0) {
            for (size_t i = 0; i < nread; i++) {
                if (buf[i] >= '0' && buf[i] <= '9') {
                    homebrew_count = homebrew_count * 10 + (buf[i] - '0');
                }
            }
        }
        pclose(fp);
    }

    // Check for MacPorts packages
    fp = popen(macports_cmd, "r");
    if (fp != NULL) {
        size_t nread;
        while ((nread = fread(buf, 1, BUFSIZE, fp)) > 0) {
            for (size_t i = 0; i < nread; i++) {
                if (buf[i] >= '0' && buf[i] <= '9') {
                    macports_count = macports_count * 10 + (buf[i] - '0');
                }
            }
        }
        pclose(fp);
    }

    // Print the results
    printf("Package managers:\n");
    if (homebrew_count > 0) {
        printf("- Homebrew\n");
        printf("  Packages installed: %d\n", homebrew_count);
    }
    if (macports_count > 0) {
        printf("- MacPorts\n");
        printf("  Packages installed: %d\n", macports_count);
    }
    if (homebrew_count == 0 && macports_count == 0) {
        printf("No package managers found.\n");
    }

    return 0;
}
