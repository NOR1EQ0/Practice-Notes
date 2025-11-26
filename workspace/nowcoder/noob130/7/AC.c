#include <stdio.h>

int main() {
    double c, d;
    scanf("%lf%lf", &c, &d);
    printf("%.3lf\%\n", d / c * 100.0);
}