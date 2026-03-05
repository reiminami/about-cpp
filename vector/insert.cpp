#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    colors.insert(colors.begin() + 1, "cyan");

    for(string color: colors) {
        cout << color << endl;
    }
}
