#include <iostream>
#include <algorithm>

using namespace std;

bool less_than_40(int value) {
    return value < 40;
}

int main() {
    vector<int> nums = {10, 20, 30, 40, 35};

    // find - 指定値へのイテレータ
    auto iter1 = find(nums.begin(), nums.end(), 10);
    if (iter1 != nums.end())
        cout << "FOUND: " << *iter1 << endl;

    // is_sorted_until - 昇順になっていない要素へのイテレータ
    auto iter2 = is_sorted_until(nums.begin(), nums.end());
    cout << "IS_SORTED_UNTIL: " << *iter2 << endl;

    // min_element - 最小要素へのイテレータ
    auto iter3 = min_element(nums.begin(), nums.end());
    cout << "MIN_ELEMENT: " << *iter3 << endl;

    // max_element - 最大要素へのイテレータ
    auto iter4 = max_element(nums.begin(), nums.end());
    cout << "MAX_ELEMENT: " << *iter4 << endl;

    // lower_bound - 指定値以上の要素へのイテレータ
    auto iter5 = lower_bound(nums.begin(), nums.end(), 30);
    cout << "LOWER_BOUND: " << *iter5 << endl;

    // upper_bound - 指定値より大きい要素へのイテレータ
    auto iter6 = upper_bound(nums.begin(), nums.end(), 30);
    cout << "UPPER_BOUND: " << *iter6 << endl;

    // find_first_of - 随時検索
    vector<int> temps = {40, 50, 20, 10};
    auto iter7 = find_first_of(nums.begin(), nums.end(), temps.begin(), temps.end());
    cout << "FIND_FIRST_OF: " << *iter7 << endl;

    // find_if - 条件一致する最初の要素へのイテレータ
    auto iter8 = find_if(nums.begin(), nums.end(), less_than_40);
    cout << *iter8 << endl;
}
