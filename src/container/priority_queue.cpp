#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> nums;   // 初期化 (昇順)
    nums.push(10);  // 値[0]を追加
    nums.push(20);
    nums.push(30);

    // ループ
    while (!nums.empty()) {
        cout << nums.top() << endl;
        nums.pop(); // 削除
    }
}
