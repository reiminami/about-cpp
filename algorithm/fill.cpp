#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers(5);
    fill(numbers.begin(), numbers.end(), 0);

    for(int number : numbers) {
        cout << number << endl;
    }
}
