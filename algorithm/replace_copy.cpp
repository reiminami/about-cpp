#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> member = {"John", "Paul", "Ringo"};
    vector<string> new_member(3);
    replace_copy(member.begin(), member.end(), new_member.begin(), (string)"Ringo", (string)"George");
    for (string p : member) {
        cout << p << "\n";   // John Paul Ringo
    }
    for (string np : new_member) {
        cout << np << "\n";   // John Paul George
    }
}
