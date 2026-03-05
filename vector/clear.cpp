#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    cout << colors.at(0) << endl;
    colors.clear();
    cout << colors.at(0) << endl;
}
