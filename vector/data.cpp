#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    string* d = colors.data();
    cout << d[0];   // red
}
