#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static signed int* build_bad_char_table(char* pattern, size_t pattern_len) {
    signed int* ret = (signed int*)malloc(sizeof(signed int)*256);
    char* ptr = pattern;
    for (int i = 0; i < 256; ++i) {
        ret[*ptr] = ptr - pattern;
    }
    return ret;
}

char* bm_search(char* primary, char* pattern, size_t primary_len, size_t pattern_len) {
    signed int* bad_char_table = build_bad_char_table(pattern, pattern_len);
    int slide_distance = 0;
    size_t pattern_ptr = pattern_len;
    size_t primary_ptr = primary_len;

    return NULL;
}

int main() {
    return 0;
    char pattern[1025];
    char primary[1025];
    printf("Primary: ");
    fgets(primary, sizeof(primary), stdin);
    printf("\nPattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    putchar('\n');
    printf("Primary @ %p | Pattern @ %p\n", primary, pattern);
    char* pos = bm_search(primary, pattern, sizeof(primary) - 1, sizeof(pattern) - 1);
    if (pos == NULL) {
        printf("No sub-string.\n");
    } else {
        printf("Sub-string found at %p (index %d)\n", pos, pos - primary);
    }
    return 0;
}