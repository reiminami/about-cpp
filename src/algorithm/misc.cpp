#include <iostream>
#include <algorithm>

using namespace std;

bool less_than_40(int value) {
    return value < 40;
}

void plus_one(int &value) {
    value++;
}

int main() {
    vector<int> v = {40, 10, 20, 30, 40};

    // count - 指定値の出現回数
    cout << count(v.begin(), v.end(), 40) << endl;

    // count_if - 条件一致する値の出現回数
    cout << count_if(v.begin(), v.end(), less_than_40) << endl;

    // copy - コピー
    vector<int> v2(5);
    copy(v.begin(), v.end(), v2.begin());

    // 指定値でデータ範囲を埋める
    fill(v2.begin(), v2.end(), 99);

    // 2つのデータをマージしてコピー
    vector<int> v3(10);
    merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());

    // 全ての要素に関数を実行
    for_each(v3.begin(), v3.end(), plus_one);
}
