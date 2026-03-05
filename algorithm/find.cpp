#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {5, 1, 3, 9, 6};
    auto ite = find(numbers.begin(), numbers.end(), 9);

    if (ite != numbers.end()) {
        cout << "9 found";
    }
}
