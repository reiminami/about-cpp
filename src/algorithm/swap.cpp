#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // swap - 2つの変数の値を交換
    int a = 100;
    int b = 200;
    swap(a, b);

    // swap_ranges - 2つの配列の指定範囲の要素を交換
    vector<int> x = {10, 20, 30};
    vector<int> y = {50, 60, 70, 80, 90};
    swap_ranges(x.begin(), x.end(), y.begin());
}
