#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <stdint.h>

void* print(void* arg) {
    for (uint16_t i = (uint16_t)(uintptr_t)arg; i < arg + 100; ++i) {
        printf("%u\n", i);
    }

    return NULL;
}

int main() {
    uint16_t num = 567;
    pthread_t threads[4];
    for (int i = 0; i < 4; ++i) {
        pthread_create(&threads[i], NULL, print, (void*)(uintptr_t)num);
    }

    for (int i = 0; i < 4; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}