#include <stdio.h>

int main()
{
    char c = 1;
    short int s = 2;
    int i = 3;
    unsigned int u = 4;
    long int l = 5;
    unsigned long int ul = 6;
    float f = 7.05;
    double d = 8.8;
    long double ld = 9.5;

    printf("Before conversion:\nSize of c:%ld | Number of c:%d\n",sizeof(c),c);

    i=i+c;

    printf("After conversion:\nSize of c:%ld | Number of c:%d\n",sizeof(c),c);
    return 0;
}