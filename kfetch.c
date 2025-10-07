#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

#define reset "\e[0m"

int main() {
    struct utsname osInfo;
    FILE *fp;
    char buffer[512];
    
    printf(BLU "kfetch v0.1: \n\n" reset);
    // Call uname to get system information
    if (uname(&osInfo) == 0) {
        // Print the kernel version
        printf("Kernel Version: %s\n", osInfo.release);
    } else {
        perror(RED "uname failed" reset);
    }
    
    fp = fopen("/etc/os-release", "r");
    if (fp == NULL) {
        perror("Error opening /etc/os-release");
        return 1;
    }
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}
