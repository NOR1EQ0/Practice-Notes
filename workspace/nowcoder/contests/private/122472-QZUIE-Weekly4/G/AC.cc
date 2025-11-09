#include <iostream>
constexpr char ps[] = "positive:";
constexpr char ns[] = "negative:";
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a = 10;
    int p{}, n{};
    while (a--) {
        long tmp;
        cin >> tmp;
        if (tmp > 0) p++;
        else if (tmp < 0)
            n++;
    }
    cout << ps << p << '\n'
         << ns << n << '\n';
}