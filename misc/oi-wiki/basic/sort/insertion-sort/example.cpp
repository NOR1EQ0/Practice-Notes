#include <bits/stdc++.h>

using namespace std;

template<typename ElemType = int, typename = enable_if<is_arithmetic<ElemType>::value, void>>
void insertion_sort(vector<ElemType>& vec) {
    auto len = vec.size();
    for (size_t i = 1; i < len; ++i) {
        ElemType key = vec[i]; // 先用临时变量存储这一元素的值
        size_t j = i - 1; 
        // 开始向前寻找比 key 更小的数，寻找过程中的数字均往后移动一位
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j]; j--;
        }
        // 找到这个值，把 key 还原。如果一直找到开头，j 此时为 -1，这个时候自然把这值排在第一个元素，也就是最小的地方。
        vec[j + 1] = key;
    }
}

#define read
#undef read

int main() {
    string operation;
    vector<int> inputVec = { 8,2,6,3,10,9,4,1,7,5 }; // OI-Wiki 的示例数组
#ifdef read
    cout << "Use example or read data from cin (example/[cin/number]):";
    while (true) {
        cin >> operation;
        for_each(operation.begin(), operation.end(), [](string::value_type& val) { val = tolower(val); });
        if (operation.front() == 'e') {
            insertion_sort(inputVec);
            break;
        } else if ([&operation]() -> bool { for (const auto i : operation) { if (i > '9' or i < '0') return false; } return true; }()) {
            int inSize = atoi(operation.c_str());
            inputVec.resize(inSize);
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
        } else if (operation == "cin") {
            int inSize; cin >> inSize; inputVec.resize(inSize); ios::sync_with_stdio(false); cin.tie(nullptr);
            for (int i = 0; i < inSize; ++i) cin >> inputVec[i];
            break;
        } else
            continue;
    }
#endif
    cout << "\nInput array: ";
    for (const auto i : inputVec) cout << i << ' ';
    insertion_sort(inputVec);
    cout << "\nSorted array: ";
    for (const auto i : inputVec) cout << i << ' ';
    cout << '\n';
    return 0;
}