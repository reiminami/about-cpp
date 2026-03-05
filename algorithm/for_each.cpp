#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void plusOne(int &value) {
    value++;
}

int main() {
    vector<int> nums = {30, 10, 60, 50};
    for_each(nums.begin(), nums.end(), plusOne);

    for (int num: nums) {
        cout << num << endl;
    }
}
