#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    colors.resize(2);

    for(string color: colors) {
        cout << color << endl;
    }
}
