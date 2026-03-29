#pragma once
#include "List.hpp"

namespace bubbleSort {
    void run() {
        List list;
        list.add(14);
        list.add(13);
        list.add(12);
        list.add(6);
        list.add(5);
        list.add(4);
        list.add(3);
        list.add(2);
        list.add(1);

        int n = list.size();

        for (int i=0; i<n; i++) {
            for (int j=1; j<n; j++) {
                if (list[j] < list[j - 1]) {
                    std::swap(list[j], list[j - 1]);
                    list.print({j, j-1});
                }
            }
        }
        list.print();
        std::cout << "Sorted" << std::endl;
    }
}
