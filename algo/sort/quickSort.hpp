#pragma once
#include "List.hpp"

namespace quickSort {
    int partition(List& list, int left, int right) {
        int pivot = list[right];
        int i = left - 1;

        for (int j=left; j<right; j++) {
            if (list[j] < pivot) {
                i++;
                std::swap(list[i], list[j]);
                list.print({i, j});
            }
        }

        std::swap(list[i + 1], list[right]);
        list.print({i+1, right});
        return i + 1;
    }

    void sort(List& list, int left, int right) {
        if (left < right) {
            int pi = partition(list, left, right);
            sort(list, left, pi - 1);
            sort(list, pi + 1, right);
        }
    }

    void sort(List& list) {
        if (list.size() > 0) {
            sort(list, 0, list.size() - 1);
        }
    }

    void run() {
        List list;
        list.add(14);
        list.add(12);
        list.add(5);
        list.add(13);
        list.add(4);
        list.add(3);
        list.add(2);
        list.add(1);

        sort(list);

        list.print();
        std::cout << "Sorted" << std::endl;
    }
}
