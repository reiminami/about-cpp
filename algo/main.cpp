#include <iostream>
#include "search/bfs.hpp"
#include "search/dfs.hpp"
#include "search/bestFirstSearch.hpp"
#include "sort/bubbleSort.hpp"
#include "sort/insertionSort.hpp"
#include "sort/quickSort.hpp"
#include "sort/mergeSort.hpp"
#include "sort/heapSort.hpp"

using namespace std;

struct Algo {
    string name;
    function<void()> run;
};

void output(vector<Algo> algos) {
    string txt = "\nアルゴリズム (0: 終了, ";
    for (int i=0; i<algos.size(); i++) {
        txt += to_string(i + 1) + ": " + algos[i].name;
        if (i < algos.size() - 1)
            txt += ", ";
    }
    txt += ")\nSELECT > ";
    cout << txt;
}

int main() {
    // アルゴリズム一覧
    vector<Algo> algos {
        {"BFS", bfs::run},
        {"DFS", dfs::run},
        {"最良優先探索", bestFirstSearch::run},
        {"バブルソート", bubbleSort::run},
        {"挿入ソート", insertionSort::run},
        {"クイックソート", quickSort::run},
        {"マージソート", mergeSort::run},
        {"ヒープソート", heapSort::run},
    };

    while (true) {
        output(algos);
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
