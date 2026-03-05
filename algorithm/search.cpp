#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 5, 9, 12, 15};
    vector<int> target = {3, 5};

    if ( search(nums.begin(), nums.end(), target.begin(), target.end())     != nums.end() ) {
        cout << "target found";
    } else {
        cout << "not found";
    }
}
