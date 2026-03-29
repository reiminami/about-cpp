#pragma once
#include "List.hpp"


#define LEFT_CHILD(i)   (((i) + 1) * 2 - 1)
#define RIGHT_CHILD(i)  (((i) + 1) * 2)
#define PARENT(i)       (((i) + 1) / 2 - 1)

namespace heapSort {
    static void upheap(List& list, int n) {
        while (n > 0) {
            int m = PARENT(n);
            if (list[m] < list[n]) {
                std::swap(list[m], list[n]);
                list.print({m, n}, 50);
            } else {
                break;
            }
        }
    }

    static void downheap(List& list, int n) {
        int m = 0;

        while (true) {
            int tmp = m;
            int leftChild  = LEFT_CHILD(m);
            int rightChild = RIGHT_CHILD(m);

            if (leftChild >= n) break;
            if (list[leftChild] > list[tmp]) tmp = leftChild;
            if ((rightChild < n) && (list[rightChild] > list[tmp])) tmp = rightChild;
            if (tmp == m) break;
            std::swap(list[tmp], list[m]);
            list.print({tmp, m}, 50);
            m = tmp;
        }
    }

    static void sort(List& list, int n) {
        int i = 0;
        while (++i < n) {
            upheap(list, i);
        }
        while (--i > 0) {
            std::swap(list[0], list[i]);
            list.print({0, i});
            downheap(list, i);
        }
    }

    void run() {
        List list;
        list.add({11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
        const int n = list.size();
        sort(list, n);

        list.print();
        std::cout << "Sorted" << std::endl;
    }
}
