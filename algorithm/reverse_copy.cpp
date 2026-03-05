#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 5, 9};
    vector<int> n_nums(4);
    reverse_copy(nums.begin(), nums.end(), n_nums.begin());

    for (int num: n_nums) {
        cout << num << " "; // 9 5 3 1
    }
}
