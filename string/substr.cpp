#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt = "Hello World";
    cout << txt.substr(3) << endl;  // lo World
    txt = "Hello World";
    cout << txt.substr(3, 4) << endl;   // lo W
}
