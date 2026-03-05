#include <iostream>
#include <tuple>
using namespace std;

int main() {
    tuple<string, int, int> person = {"John", 21, 170};
    string name = get<0>(person);
    int age;
    int height;
    tie(name, age, height) = (person);
    cout << name << " " << age << " " << height << endl;
}
