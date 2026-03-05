#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {10, 90, 50, 70};
    vector<int> nums(5);
    copy(numbers.begin(), numbers.end(), nums.begin());

    for(int num: nums) {
        cout << num << endl;
    }
}
