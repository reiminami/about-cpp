#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream f("test.txt");
    f << "Hello!" << endl;
    f << "WORLD!" << endl;
    f.close();
}
