#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    colors.push_back("pink");

    for(string color: colors) {
        cout << color << endl;
    }
}
