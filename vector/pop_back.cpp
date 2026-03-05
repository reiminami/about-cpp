#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    colors.pop_back();

    for(string color: colors) {
        cout << color << endl;
    }
}
