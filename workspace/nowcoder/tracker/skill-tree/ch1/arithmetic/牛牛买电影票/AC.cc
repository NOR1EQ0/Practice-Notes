#include <iostream>

using namespace std;

int main() {
    char c;
    while ((c = getchar()) != '\n') {
        putchar(c);
    }
    puts("00\n");
}