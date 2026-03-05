#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool HasO(string item) {
    return item.find('o') != string::npos;
}

int main() {
    vector<string> member = {"John", "Paul", "Ringo"};
    replace_if(member.begin(), member.end(), HasO, (string)"----");
    for (string p : member) {
        cout << p << "\n";   // ---- Paul ----
    }
}
