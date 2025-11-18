#include <bits/stdc++.h>

using namespace std;

template<typename ElemType = int, typename = enable_if<is_arithmetic<ElemType>::value>>
void bubble_sort(vector<ElemType>& _vector, bool _greater = true) {
    bool flag = true;
    auto len = _vector.size();
    while (flag) {
        flag = false;
        for (int i = 0; i < len - 1; ++i)
            if ((_greater ? greater<ElemType>()(_vector[i], _vector[i + 1]) : less<ElemType>()(_vector[i], _vector[i + 1])))
                swap((flag = true, _vector[i]), _vector[i + 1]);
        len--;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;vector<int> vec(n);for (int i = 0; i < n; ++i) cin >> vec[i];
    cout << "\nInput array: ";
    for (const auto& i : vec) {
        cout << i << ' ';
    }
    bubble_sort(vec);
    cout << "\nSorted array: ";
    for (const auto& i : vec) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}