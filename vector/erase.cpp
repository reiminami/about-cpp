#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    colors.erase(colors.begin() + 1);
    cout << colors.at(0) << endl;   // red
    cout << colors.at(1) << endl;   // yellow
}
