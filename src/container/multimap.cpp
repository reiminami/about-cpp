#include <iostream>
#include <map>

using namespace std;

int main() {
    multimap<char, int> nums;   // 初期化
    nums.emplace('C', 30);      // 追加
    nums.emplace('A', 10);
    nums.emplace('B', 20);
    nums.emplace('C', 35);

    auto cnt = nums.count('C'); // 要素数
    cout << "Count: " << cnt << endl;

    auto c = nums.equal_range('C');
    for (auto iter=c.first; iter!=c.second; ++iter) {
        cout << iter->second << endl;
    }
}
