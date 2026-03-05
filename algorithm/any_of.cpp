#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool lessThan10(int value) {
    return value < 10;
}

int main() {
    vector<int> numbers = {1, 9, 5, 7};
    if (any_of(numbers.begin(), numbers.end(), lessThan10)) {
        cout << "yes";
    }
}
