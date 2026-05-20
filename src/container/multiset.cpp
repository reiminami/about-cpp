#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> nums = {30, 40, 10};  // 初期化
    nums.insert(30);                    // 追加
    size_t cnt = nums.count(30);        // キーに該当する要素数

    // ループ
    for (int num : nums) {
        cout << num << endl;
    }

    // 検索
    decltype(nums)::iterator iter = nums.find(30);
    if (iter != nums.end()) {
        // 発見
        for (size_t i=0; i<cnt; ++i) {
            int value = *iter;
            cout << "Value: " << value << endl;
            ++iter;
        }
    } else {
        cout << "Not Found" << endl;
    }
}
