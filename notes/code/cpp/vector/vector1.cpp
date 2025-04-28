#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = { 1,5,3,6,2,6 };
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ) {
        // cout << it.base() << " ";
        if (*it % 2 == 0)
            it = nums.erase(it);
        else
            ++it;
    }
    cout << '\n';
    for (int i : nums) { cout << i << " "; } 
    cout << endl;
}
