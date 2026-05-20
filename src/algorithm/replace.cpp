#include <iostream>
#include <algorithm>

using namespace std;

bool less_than_40(int value) {
    return value < 40;
}

int main() {
    vector<int> nums = {10, 20, 30, 40, 50};

    // replace - 指定値を別の値に置換
    replace(nums.begin(), nums.end(), 10, 15);

    // replace_if - 条件付きでreplace (一致した条件を99に置換)
    replace_if(nums.begin(), nums.end(), [](int x) {
        return x % 2 != 0;
    }, 99);

    // replace_copy - replaceしてコピー
    vector<int> nums2(5);
    replace_copy(nums.begin(), nums.end(), nums2.begin(), 40, 50);

    // replace_copy_if - 条件付きでreplaceしてコピー
    vector<int> nums3(5);
    replace_copy_if(nums.begin(), nums.end(), nums3.begin(), less_than_40, 88);
}
