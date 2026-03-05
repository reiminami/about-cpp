#include <iostream>
using namespace std;

int main() {
    pair<string, int> person = {"John", 22};
    string name = get<0>(person);
    int age = get<1>(person);
    name = person.first;
    age = person.second;
    tie(name, age) = person;
    cout << name << " " << age << endl;
}
