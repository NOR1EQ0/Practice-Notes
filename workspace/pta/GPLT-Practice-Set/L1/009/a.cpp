#include <bits/stdc++.h>

using namespace std;

int arr[200];
int num = 0, den = 0;

void setnum(int* ptr) {
    auto& num1 = *ptr;
    auto& den1 = *(ptr + 1);
    auto maxden = max(den, den1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d/%d", arr + i * 2, arr + i * 2 + 1);
    }
    for (int i = 0; i < n; ++i) {
        auto ptr = arr + i * 2;
        setnum(ptr);
    }
}