#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> nums = {10, 20, 30};  // 初期化
    nums.push_front(5);                     // 先頭に値[0]を追加
    nums.insert_after(nums.begin(), 99);    // 位置[0]の後ろに値[1]を追加

    // ループ
    for_each(nums.cbegin(), nums.cend(), [](int x) {
        cout << x << endl;
    });
}
