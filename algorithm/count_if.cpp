#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool greaterThan50(int value) {
    return value > 50;
}

int main() {
    vector<int> numbers = {10, 90, 50, 70, 90};
    cout << count_if(numbers.begin(), numbers.end(), greaterThan50);
}
