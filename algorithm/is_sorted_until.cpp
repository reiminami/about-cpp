#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {10, 30, 90, 70};
    auto ite = is_sorted_until(nums.begin(), nums.end());
    int pos = ite - nums.begin();
    cout << pos << endl;    // 3
}
