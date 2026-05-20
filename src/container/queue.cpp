#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> nums;    // 初期化
    nums.push(10);      // 先頭に値[0]を追加
    nums.push(20);
    nums.push(30);

    // ループ
    while (!nums.empty()) {
        cout << nums.front() << " ";
        nums.pop();     // 先頭要素を削除
    }
}
