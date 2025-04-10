#include <stdio.h>
#include <string.h>

typedef struct pair
{
    char* str;
    int val;
} pair;


int main() {
    // n = num of words, m = list.len
    int n,m;

    // Read
    scanf("%d%d",&n,&m);
    char strarr[n][26];
    int max_len = 0;
    int word_freq[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", strarr[i], &word_freq[i]);
        if (strlen(strarr[i]) > max_len) {
            max_len = strlen(strarr[i]);
        }
    }
    char dict[m][max_len+1];
    
    // Add single-letter word
    

    return 0;
}