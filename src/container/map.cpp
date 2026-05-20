#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> nums;                // 初期化
    nums.insert(make_pair('A', 10));    // 追加
    nums.insert(make_pair('C', 30));
    nums.insert(make_pair('B', 20));

    int value = nums.at('B');
    cout << "Value: " << value << endl;
}
