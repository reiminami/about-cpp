#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    cout << colors.size() << endl;

    for(string color: colors) {
        cout << color << endl;
    }
}
