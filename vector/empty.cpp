#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> colors = {"red", "green", "yellow"};
    cout << colors.empty() << endl;
    colors.clear();
    cout << colors.empty() << endl;
}
