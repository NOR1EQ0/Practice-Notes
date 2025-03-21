#include <stdio.h>
#include <stdbool.h>

const int dayOfMonths[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

// 验闰年
bool check(int n) {
    if (n % 400) {
        if (n % 4 == 0 && n % 100) {
            return true;
        }
        else
            return false;
    }
    else {
        return true;
    }
}

int main(int argc, char const* argv[]) {
    /**
     * 1900.1.1 - 9999.12.31
     */
    int num = 0;
    for (int i = 1900; i <= 9999; ++i) { // Year
        bool leap = check(i);
        int yearSum =
            + i / 1000 // 1
            + i % 1000 / 100 // 2
            + i % 100 / 10 // 3
            + i % 10 / 1; // 4
        for (int j = 1; j < 13; ++j) { // Month
            int monthSum = j % 10 + j / 10;
            for (int k = 1; k <= dayOfMonths[j - 1] + (j == 2 ? leap : 0); ++k) { // Day
                int daySum = k % 10 + k / 10;
                if (yearSum == monthSum + daySum) {
                    num++;
                }
            }
        }

    }
    printf("%d\n", num);
    return 0;
}


