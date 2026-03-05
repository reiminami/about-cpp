#include <iostream>
#include <vector>
using namespace std;

bool GreaterThan10(int value) {
    return value > 10;
}

int main() {
    vector<int> nums = {5, 9, 1, 9};
    if (none_of(nums.begin(), nums.end(), GreaterThan10)) {
        cout << "ok";
    } else {
        cout << "ng";
    }
}
