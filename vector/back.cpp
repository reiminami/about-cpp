#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    cout << colors.back() << endl;  // yellow
    cout << colors.front() << endl; // red
}
