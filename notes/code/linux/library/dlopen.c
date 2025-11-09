#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h> // Linux DLL

char* dll_filenames[] = {"test.so"};

int main() {
    char* cwd = getcwd(NULL, 0);
    printf("Current working directory: %s\n", cwd);
    
}