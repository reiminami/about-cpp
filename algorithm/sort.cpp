#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 9, 7, 5};
    sort(nums.begin(), nums.end());
    for (int num: nums) {
        cout << num << " "; // 1 5 7 9
    }
}
