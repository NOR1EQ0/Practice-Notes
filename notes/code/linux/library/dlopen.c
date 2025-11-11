#include <dlfcn.h> // Linux DLL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main() {
    const char* cwd = getcwd(NULL, 0); // GNU Extension
    const char lib_path[] = "./testlib.so";    
    printf("Current working directory: %s\n", cwd);
    void* lib_handle = dlopen(lib_path, RTLD_LAZY | RTLD_LOCAL);
    if (lib_handle == NULL) {
        puts("Unable to open target lib!");
        printf("dlerror(): %s\n", dlerror());
        return EXIT_FAILURE;
    } else {
        printf("Succeeded to open %s! Handle pointer: %p\n", lib_handle);
    }
    void (*target_func)(void) = dlsym(lib_handle, "test_func");
    target_func();
    puts("Test Done!");
}