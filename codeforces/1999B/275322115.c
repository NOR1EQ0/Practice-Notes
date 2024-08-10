#include <stdio.h>
#include <stdlib.h>

int main() {
    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        int nums[4];
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            scanf("%d", &nums[i]);
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 2; j < 4; ++j) {
                int x = 0, y = 0;
                if (nums[i] > nums[j])
                    x++;
                if (nums[1 - i] > nums[5 - j])
                    x++;
                if (nums[i] < nums[j])
                    y++;
                if (nums[1 - i] < nums[5 - j])
                    y++;
                if (x > y) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}