#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // binary_search - ソート済みデータへの効率的な検索
    vector<int> v = {10, 30, 50, 70};
    cout << binary_search(v.begin(), v.end(), 50) << endl;

    // search - 別のデータで指定された値のシーケンスを検索
    vector<int> v2 = {10, 30, 50, 80};
    cout << (search(v.begin(), v.end(), v2.begin(), v2.end()) != v.end());
}
