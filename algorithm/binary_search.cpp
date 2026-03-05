#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {10, 90, 50, 70};
    sort(numbers.begin(), numbers.end());

    if (binary_search(numbers.begin(), numbers.end(), 4)) {
        cout << "4 found";
    }
    if (binary_search(numbers.begin(), numbers.end(), 50)) {
        cout << "50 found";
    }
}
