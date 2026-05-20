#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream f("test.txt", ios::app);
    f << "Hi" << endl;
    f << "WRLD" << endl;
    f.close();
}
