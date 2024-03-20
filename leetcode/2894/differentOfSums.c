#include <stdio.h>

int differenceOfSums(int n, int m)
{
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i%m==0){
            num2+=i;
        }
        else
        {
            num1+=i;
        }
    }
    return num1-num2;
}

int main(){
    int n=10,m=3;
    int result=differenceOfSums(n,m);
    printf("n=19 m=3\n");
    printf("Expected Output: 19\n");
    printf("Result: %d\n",result);
    return 0;
}