#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convertDateToBinary(char* date) {
    int year, mon, day, q1 = 0, q2 = 0;
    char* str = (char*)malloc(sizeof(char) * 256);
    char* year_ = (char*)malloc(sizeof(char) * 16);
    char* mon_ = (char*)malloc(sizeof(char) * 16);
    char* day_ = (char*)malloc(sizeof(char) * 16);
    memset(year_, '\0', sizeof(char) * 16);
    memset(mon_, '\0', sizeof(char) * 16);
    memset(day_, '\0', sizeof(char) * 16);
    date[4] == '\0';
    date[7] == '\0';
    year = atoi(date);
    mon = atoi(&date[5]);
    day = atoi(&date[8]);
    for (int i = 0, base = year, expo = 0; i < 256; ++i) {
        base = base / 2;
        expo = base % 2;
        if (base / 2) {
            if (expo) {
                str[i] = '1';
            } else {
                str[i] = '0';
            }
        }
    }
    
    free(year_);
    free(mon_);
    free(day_);
    return str;
}

void DtoB(int d) {
    if (d / 2)
        DtoB(d / 2);
    printf("%d", d % 2);
}

int main() {
    char* a = convertDateToBinary("1900-01-01");
    printf("%s", a);
    return 0;
}