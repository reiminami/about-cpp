#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 5, 9};

    if (is_sorted(nums.begin(), nums.end())) {
        cout << "sorted";
    } else {
        cout << "not sorted";
    }
}
