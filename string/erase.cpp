#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt = "Hello World";
    cout << txt << endl;    // Hello World
    txt.erase(4);
    cout << txt << endl;    // Hell
}
