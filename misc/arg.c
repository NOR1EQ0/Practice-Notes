#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRETEXT "Default Arg"

int main(int argc, char const* argv[]) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d] @ %p: %s\n", i, &(argv[i]), argv[i]);
    }
    char* arg = PRETEXT;
    printf("arg (before handle argv) @ %p: %s\n", &arg, arg);
    if (argc != 1) {
        arg = malloc(sizeof(char) * (strlen(argv[1]) + 1));
        memcpy(arg, argv[1], strlen(argv[1]) + 1);
    }

    printf("arg @ %p: %s\n", &arg, arg);
    return 0;
}