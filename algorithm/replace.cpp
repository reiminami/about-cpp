#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> member = {"John", "Paul", "Ringo"};
    replace(member.begin(), member.end(), (string)"Ringo", (string)"George");
    for (string p : member) {
        cout << p << " ";   // John Paul George
    }
}
