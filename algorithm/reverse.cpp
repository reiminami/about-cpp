#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 5, 9};
    reverse(nums.begin(), nums.end());

    for (int num: nums) {
        cout << num << " "; // 9 5 3 1
    }
}
