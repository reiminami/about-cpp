#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream f("test.txt", ios::app);
    f << "hey";
    f.close();
}
