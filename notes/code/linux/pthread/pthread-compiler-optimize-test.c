#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool flag = 1;

void* change_flag() {
    flag = false;
    printf("Change the flag at %p now.\n", &flag);
    return NULL;
}

int main() {
    pthread_t pth1;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int p = pthread_create(&pth1, &attr, change_flag, NULL);
    if (p != 0) {
        printf("Unable to create a thread. Error code: %d\n", p);
        return EXIT_FAILURE;
    }
    size_t cnt = 1;
    while (flag) {
        printf("Count: %u\n", cnt++);
    }
    int j = pthread_join(pth1, NULL);
    printf("Join: %d\n", j);
    return EXIT_SUCCESS;
}