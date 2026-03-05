#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 5, 3};
    vector<int> search = {1, 3, 5};
    sort(nums.begin(), nums.end());
    sort(search.begin(), search.end());

    if (includes(nums.begin(), nums.end(), search.begin(), search.end())) {
        cout << "found";
    } else {
        cout << "not found";
    }
}
