#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {10, 5, 9, 2};
    auto ite = max_element(nums.begin(), nums.end());

    if (ite != nums.end()) {
        cout << *ite;   // 10
    }
}
