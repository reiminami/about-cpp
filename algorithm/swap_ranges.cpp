#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    swap_ranges(nums.begin()+1, nums.begin()+3, nums.begin()+5);
    for (int num: nums) {
        cout << num << " "; // 1 11 13 7 9 3 5
    }
}
