#include <iostream>
#include "bfs.hpp"
#include "dfs.hpp"
using namespace std;

struct Algo {
    string name;
    function<void()> run;
};

int main() {
    // アルゴリズム一覧
    vector<Algo> algos {
        {"bfs", bfs::run},
        {"dfs", dfs::run},
    };

    while (true) {
        cout << endl << "ALGORITHM(0: EXIT,\t";
        for (int i=0; i<algos.size(); i++) {
            cout << i + 1 << ": " << algos[i].name;
            if (i < algos.size()-1)
                cout << ",\t";
        }
        cout << ")" << endl << "SELECT > ";

        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0) break;
        if (choice >= 1 && choice <= algos.size())
            algos[choice - 1].run();
        else
            cout << "?" << endl;
    }
}
