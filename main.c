#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char* path = getenv("PATH");
    char* entry;
    const char* entries[500];
    for (int i = 0; i < 500; ++i) {
        entries[i] = "\0";
    }
    int idx = 0;
    while ((entry = strsep(&path, ":"))) {
        int should_add = 1;
        for (int i = 0; i < 500; ++i) {
            if (entries[i] == entry) {
                should_add = 0;
                break;
            }
            if (!strcmp(entries[i], "\0")) {
                break;
            }
        }
        if (should_add == 1) {
            entries[idx] = entry;
            ++idx;
        }
    }
    for (int i = 0; i < 500; ++i) {
        if (strcmp(entries[i], "\0") == 0) break;
        printf("%s", entries[i]);
        if (strcmp(entries[i + 1], "\0") != 0) {
            printf(":");
        }
    }
    return 0;
}
