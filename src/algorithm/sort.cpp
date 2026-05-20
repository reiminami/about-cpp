#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {40, 30, 10, 20};

    // 昇順
    sort(v.begin(), v.end());

    // 逆順
    reverse(v.begin(), v.end());

    // 逆順要素のコピー
    vector<int> v2(4);
    reverse_copy(v.begin(), v.end(), v2.begin());
}
