#include <stdio.h>

int finalValueAfterOperations(char **operations, int operationsSize)
{
    int ans=0;
    for (char i = 0; i < operationsSize; i++)
    {
        if (operations[i][1] == '+')
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    return ans;
}

int main()
{
    char *operations[] = {"--X", "X++", "X++"};
    printf("%d",finalValueAfterOperations(operations, 3));
    return 0;
}
