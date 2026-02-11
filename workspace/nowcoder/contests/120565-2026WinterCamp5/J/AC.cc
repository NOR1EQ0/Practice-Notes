#include <bits/stdc++.h>

using namespace std;

bool table[9];
int arr[3][3];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int lastsum = 0;
    for (int i = 0; i < 3; i++) {
        int rowsum = 0;
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
            rowsum += arr[i][j];
            table[arr[i][j] - 1] = true;
        }
        if (lastsum) {
            if (lastsum != rowsum) {
                cout << "No\n";
                return 0;
            }
        } else {
            lastsum = rowsum;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (!table[i]) {
            cout << "No\n";
            return 0;
        }
    }

    int d1 = arr[0][0] + arr[1][1] + arr[2][2];
    int d2 = arr[0][2] + arr[1][1] + arr[2][0];
    if (d1 != lastsum || d2 != lastsum) {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        int colsum = 0;
        for (int j = 0; j < 3; j++) {
            colsum += arr[j][i];
        }
        if (colsum != lastsum) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}