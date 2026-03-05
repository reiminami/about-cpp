#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 3> arr = {10, 20, 30};
    int n = arr.size();
    for (int i=0; i<n; i++) {
        cout << arr[i] << endl;
    }
}
