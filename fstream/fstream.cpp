#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream f("test.txt");
    f << "hello world";

    string txt;
    getline(f, txt);
    cout << txt;

    f.close();
}
