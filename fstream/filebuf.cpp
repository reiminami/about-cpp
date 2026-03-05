#include <iostream>
#include <fstream>
using namespace std;

int main() {
    filebuf fb;
    fb.open("test.txt", ios_base::out);
    fb.sputn("Hello, World", 13);
    fb.close();
}
