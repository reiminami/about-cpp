#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    auto vdata = v.data();
    cout << *vdata << endl;
}
