#include <bits/stdc++.h>

using namespace std;

using student = tuple<string, string, int>;

student s[105]{};

void print_student(const student& stu) {
    cout << get<0>(stu) << ' ' << get<1>(stu) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    size_t n;
    cin >> n;
    int maxn = INT_MIN, minn = INT_MAX;
    size_t maxi{}, mini{};
    for (size_t i = 0; i < n; i++) {
        auto& stu = s[i];
        cin >> get<0>(stu) >> get<1>(stu) >> get<2>(stu);
        auto& score = get<2>(stu);
        if (score >= maxn) {
            maxn = score;
            maxi = i;
        }
        if (score <= minn) {
            minn = score;
            mini = i;
        }
    }
    print_student(s[maxi]);
    print_student(s[mini]);
}