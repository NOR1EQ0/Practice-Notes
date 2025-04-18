#include <bits/stdc++.h>
#define power(x) (x)*(x)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Notice: input data maybe float
    double pts[6];
    double circumference = 0;
    for (int i = 0; i < 6; ++i) {
        cin >> pts[i];
    }
    for (int i = 0; i < 3; ++i) {
        auto& x1 = pts[i * 2], &y1 = pts[i * 2 + 1], &x2 = pts[(i * 2 + 2) % 6], &y2 = pts[(i * 2 + 3) % 6];
        // maybe I can use `std::rotate`?
        double line = sqrt(power(x2-x1)+power(y2-y1));
        circumference += line;
    }
    cout << fixed << setprecision(2) << circumference << '\n';
    return 0;
}