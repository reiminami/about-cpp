#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors1 = {"red", "green"};
    vector<string> colors2 = {"yellow", "blue"};
    colors1.swap(colors2);

    for(string color: colors1) {
        cout << color << endl;
    }
}
