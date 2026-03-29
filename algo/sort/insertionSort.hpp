#pragma once
#include "List.hpp"

namespace insertionSort {
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

        for (int i=1; i<n; i++) {
            if (list[i - 1] > list[i]) {
                int j = i;
                int temp = list[i];
                do {
                    std::swap(list[j], list[j - 1]);
                    list.print({j, j-1});
                    j--;
                } while (j > 0 && list[j - 1] > temp);
                list[j] = temp;
            }
        }

        list.print();
        std::cout << "Sorted" << std::endl;
    }
}
