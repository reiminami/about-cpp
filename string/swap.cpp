#include <iostream>
#include <string>
using namespace std;

int main() {
    string hello = "hello";
    string world = "world";
    hello.swap(world);

    cout << hello << " " << world << endl;  // world hello
}
