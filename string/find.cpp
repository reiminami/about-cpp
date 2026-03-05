#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt = "Hello World";
    cout << txt.find("o") << endl;  // 4
    cout << txt.rfind("o") << endl; // 7
}
