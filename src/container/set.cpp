#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> nums = {30, 10, 40};   // 初期化
    nums.insert(50);    // 追加

    // ループ
    for (int num : nums) {
        cout << num << endl;
    }

    // 検索
    decltype(nums)::iterator iter = nums.find(40);
    if (iter != nums.end()) {
        // 発見
        int value = *iter;
        cout << "Value: " << value << endl;
    } else {
        cout << "Not Found" << endl;
    }
}
