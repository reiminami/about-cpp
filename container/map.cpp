#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<string, int> member = {
        {"John", 21},
        {"Paul", 22},
    };
    cout << member["John"] << endl;
}
