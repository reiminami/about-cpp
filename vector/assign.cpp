#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {10, 20, 30};
    vector<int> nums2;

    nums2.assign(nums1.begin(), nums1.end());

    for(int num : nums2) {
        cout << num << endl;
    }
}
