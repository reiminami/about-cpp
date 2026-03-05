#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool HasO(string item) {
    return item.find('o') != string::npos;
}

int main() {
    vector<string> member = {"John", "Paul", "Ringo"};
    vector<string> new_member(3);
    replace_copy_if(member.begin(), member.end(), new_member.begin(), HasO, (string)"----");
    for (string np : new_member) {
        cout << np << "\n";   // ---- Paul ----
    }
}
