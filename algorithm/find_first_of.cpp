#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 7, 5, 9};
    vector<int> search = {2, 6, 7};
    auto ite = find_first_of(nums.begin(), nums.end(), search.begin(), search.end());

    if (ite!= nums.end()) {
        cout << *ite;
    }
}
