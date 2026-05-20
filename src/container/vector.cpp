#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {10, 20, 30};    // 初期化
    cout << nums[2] << endl;            // アクセス
    nums.push_back(40);                 // 末尾に値[0]を追加
    nums.insert(nums.begin() + 1, 15);  // 位置[0]に値[1]を追加
    nums.erase(nums.end() - 1);         // 位置[0]を削除
    size_t num_size = nums.size();      // 要素数

    // ループ
    for (size_t i=0; i<num_size; i++) {
        cout << nums[i] << " ";
    }

    for_each (nums.begin(), nums.end(), [](int x) {
        cout << x << " ";
    });

    for (int x : nums) {
        cout << x << " ";
    }

    for (auto&& num : nums) {
        cout << num << " ";
    }
}
