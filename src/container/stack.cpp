#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> nums;    // 初期化
    nums.push(10);      // 末尾に値[0]を追加
    nums.push(20);
    nums.push(30);

    // ループ
    while (!nums.empty()) {
        cout << nums.top() << " ";
        nums.pop();     // 末尾の値を削除
    }
}
