#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool greaterThan5(int value) {
    return value > 5;
}

int main() {
    vector<int> nums = {1, 3, 6, 5, 7, 9};
    auto ite = find_if(nums.begin(), nums.end(), greaterThan5);
    if (ite != nums.end()) {
        cout << *ite;
    }
}
