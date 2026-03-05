#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 6, 7, 8};
    vector<int> merged(8);
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

    for (int num: merged) {
        cout << num << " "; // 1 1 2 3 4 6 7 8
    }
}
