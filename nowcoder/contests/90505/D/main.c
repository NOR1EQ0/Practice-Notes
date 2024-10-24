#include <stdio.h>


int main(int argc, char const* argv[]) {
    unsigned char cipher[] = {
           198, 44, 113, 215, 43, 231, 181, 44, 147, 95, 61, 181, 79, 180, 95, 79, 180, 232, 181, 79, 46,
           95, 231, 147, 95, 164, 181, 146, 79, 65, 63, 82, 116, 77, 0 };
    for (int i = 0; i < 35; ++i) {
        cipher[i] = cipher[i] / 17;
    }for (int i = 0; i < 35; ++i)
    printf("%d,",cipher[i]);
    return 0;
}
