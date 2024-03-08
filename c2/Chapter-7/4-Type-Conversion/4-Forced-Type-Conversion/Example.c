#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float f = 3.6, frac_part, f2 = -2.6, frac2_part;
    // f > 0, f2 < 0
    int int_part = (int)f, int2_part = (int)f2;
    frac_part = f - (int)f, frac2_part = f2 - (int)f2;
    printf("f: %f\nfrac_part: %f\nint_part: %d\nf2: %f\nfrac2_part: %f\nint2_part: %d\n\n", f, frac_part, int_part, f2, frac2_part, int2_part);
    printf("sizeof(f): %ld\n", sizeof(f));
    return 0;
}
