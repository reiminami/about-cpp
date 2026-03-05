#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 5, 3, 7, 9};
    vector<int> others = {5, 3, 9, 7, 1};

    if (is_permutation(nums.begin(), nums.end(), others.begin(), others.end())) {
        cout << "permutation found";
    } else {
        cout << "no permutation found";
    }
}
