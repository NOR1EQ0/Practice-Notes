#include <bits/stdc++.h>

using namespace std;
int valid[(int)1e6];
struct bill{
    int arr[3];
};
bill bills[(int)1e6];

#define x.room (x).arr[0]
#define x.start (x).arr[1]
#define x.end (x).arr[2]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> valid[i];
    }
    for (int i = 0; i < m; ++i) {
        int a = 3;
        while (a--) {
            cin >> bills[i].arr[3-a];
        }
    }
    return 0;
}