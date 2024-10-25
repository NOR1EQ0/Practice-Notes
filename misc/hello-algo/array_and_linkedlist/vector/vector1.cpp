#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
    /* 初始化 */
    vector<int> nums1; // 无初始值
    nums1 = { 1 };
    vector<int> nums = { 1,3,2,5,4 }; // 有初始值
    cout << nums1[0] << endl;
    cout << nums[0] << endl;
    nums1.push_back(3);
    nums.emplace_back(6);
    cout << nums.size() << " " << nums.max_size() << endl;
    nums.erase(nums.begin() + 3);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
    nums.pop_back();
    for (int i: nums) {
        cout << i << " ";
    }
    return 0;
}
