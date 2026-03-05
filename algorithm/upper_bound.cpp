#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {10, 30, 90, 70};
    sort(nums.begin(), nums.end());
    auto ite = upper_bound(nums.begin(), nums.end(), 29);

    if (ite != nums.end()) {
        cout << *ite;   // 30
    }
}
