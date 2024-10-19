#include <stdio.h>
#define yes puts("Yes")
#define no puts("No")

void solve(int n, int m) {
    int rest = m - n + 3;
    int trip[3] = { rest / 3,(rest - rest / 3) / 2,rest - rest / 3 - (rest - rest / 3) / 2 };
    if (trip[0] + trip[1] > trip[2]) yes;
    else no;
}

int main(int argc, char const* argv[]) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, m;scanf("%d%d", &n, &m);
        solve(n, m);
    }
    return 0;
}
