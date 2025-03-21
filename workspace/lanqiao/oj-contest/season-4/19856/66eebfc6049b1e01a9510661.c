#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct assume {
    int key;
    int f;
    int b;
} assume;

int min(assume x) {
    if (x.b > x.f) {
        return x.f;
    }
    return x.b;
}

int main() {
    int n, list_len = 1, ans = 0;
    char a;
    assume* list = (assume*)malloc(sizeof(assume));
    scanf("%d", &n);
    scanf("%d %c", &list[0].key, &a);
    if (a == 'F') {
        list[0].f = 1;
    } else {
        list[0].b = 1;
    }
    for (int i = 1; i < n; ++i) {
        bool flag = true; // change flag
        int pay;
        char end = '\0';
        scanf("%d %c", &pay, &end);
        for (int i = 0; i < list_len; ++i) {
            if (pay == list[i].key) {
                if (end == 'F') {
                    list[i].f++;
                } else {
                    list[i].b++;
                }
                flag = false;
                break;
            }
        }
        if (flag) {
            int last = list_len;
            list_len++;
            list = (assume*)realloc(list, sizeof(assume) * list_len);
            list[last].key = pay;
            if (end == 'F') {
                list[last].f = 1;
                list[last].b = 0;
            } else {
                list[last].b = 1;
                list[last].f = 0;
            }
        }
    }
    // find min
    for (int i = 0; i < list_len; ++i) {
        ans += min(list[i]);
    }
    printf("%d\n", ans);
    return 0;
}