int countKeyChanges(char *s)
{
    int ans = 0;
    char *l = s;
    if (s[0] == '\0')
    {
        return 0;
    }
    char *r = s + 1;
    while (*r)
    {
        if (!(*l == *r || *l + 32 == *r || *l - 32 == *r))
        {
            l = r;
            ans++;
        }
        r++;
    }
    return ans;
}

int main()
{
    char *s = "aAbBcC";
    printf("%d\n", countKeyChanges(s));
    return 0;
}