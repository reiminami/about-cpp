#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {10, 90, 50, 70, 90};
    int cnt = count(numbers.begin(), numbers.end(), 90);
    cout << cnt;
}
