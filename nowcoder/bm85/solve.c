#include <stdio.h>

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 验证IP地址
 * @param IP string字符串 一个IP地址字符串
 * @return string字符串
 */
char *solve(char *IP)
{
    int protocol = 0, dot = 0, colon = 0;
    for (char *i = IP; i < *i; i++)
    {
        if(dot > 3||colon>7){
            return "Neither";
        }
        if (*i == *(i + 1) && (*i = '.' || *i == ':'))
        {
            return "Neither";
        }
    }
    if (dot != 3 || colon != 7)
    {
        return "Neither";
    }
}

int main()
{
    return 0;
}
