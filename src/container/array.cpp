#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 3> nums = {10, 20, 30};  // 初期化
    nums[2] = 99;                       // アクセス

    // ループ
    for_each(nums.begin(), nums.end(), [](int x) {
        cout << x << endl;
    });
}
