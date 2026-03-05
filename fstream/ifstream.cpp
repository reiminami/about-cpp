#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string txt;
    ifstream rf("test.txt");

    while (getline(rf, txt)) {
        cout << txt;
    }

    rf.close();
}
