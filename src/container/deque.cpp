#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> nums = {10, 20, 30};     // 初期化
    cout << nums[2] << endl;            // アクセス
    nums.push_front(5);                 // 先頭に値[0]を追加
    nums.push_back(40);                 // 末尾に値[0]を追加
    nums.pop_front();                   // 先頭を削除
    nums.pop_back();                    // 末尾を削除

    // ループ
    for_each(nums.begin(), nums.end(), [](int x) {
        cout << x << endl;
    });
}
