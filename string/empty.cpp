#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt = "Hello World";
    cout << txt.empty() << endl;    // 0
    txt = "";
    cout << txt.empty() << endl;    // 1
}
