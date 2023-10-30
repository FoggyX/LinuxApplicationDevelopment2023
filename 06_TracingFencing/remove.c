#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>

typedef int (*remove_type)(const char *filename);

int remove(const char *filename) {
    remove_type real_remove = dlsym(RTLD_NEXT, "remove");
    if (strstr(filename, "PROTECT") != NULL) {
        return 0;
    }
    return real_remove(filename);
}
