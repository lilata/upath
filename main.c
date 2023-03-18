#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_SIZE 375
int main() {
    char* path = getenv("PATH");
    char* entry;
    const char* entries[PATH_SIZE];
    for (int i = 0; i < PATH_SIZE; ++i) {
        entries[i] = "\0";
    }
    int idx = 0;
    while ((entry = strsep(&path, ":"))) {
        int should_add = 1;
        for (int i = 0; i < PATH_SIZE; ++i) {
            if (strcmp(entries[i], entry) == 0) {
                should_add = 0;
                break;
            }
            if (strcmp(entries[i], "\0") == 0) {
                break;
            }
        }
        if (should_add == 1) {
            if (idx != 0) {
                printf(":");
            }
            entries[idx] = entry;
            printf("%s", entries[idx]);
            ++idx;
        }
    }
    return 0;
}
