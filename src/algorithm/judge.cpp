#include <iostream>
#include <algorithm>

using namespace std;

bool less_than_30(int value) {
    return value < 30;
}

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // all_of - 全ての要素が条件に一致するか？
    cout << all_of(v.begin(), v.end(), less_than_30) << endl;

    // any_of - いずれかの要素が条件に一致するか？
    cout << any_of(v.begin(), v.end(), less_than_30) << endl;

    // none_of - どの条件も一致しないか？
    cout << none_of(v.begin(), v.end(), less_than_30) << endl;

    // is_sorted - 昇順か？
    cout << is_sorted(v.begin(), v.end()) << endl;

    // includes - 2つのソート済み配列で、配列Aが配列Bの要素を全て持っているか？
    vector<int> v2 = {20, 30, 40};
    cout << includes(v.begin(), v.end(), v2.begin(), v2.end()) << endl;

    // is_permutation - 片方の順列がもう片方に存在するか？
    vector<int> v3 = {50, 40, 30, 20, 10};
    cout << is_permutation(v.begin(), v.end(), v3.begin(), v3.end()) << endl;
}
