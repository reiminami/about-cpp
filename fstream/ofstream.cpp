#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream f("test.txt");
    f << "hey";
    f.close();
}
