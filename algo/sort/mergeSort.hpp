#pragma once
#include "List.hpp"

namespace mergeSort {
    void m(List& list, List& tmp, int left, int mid, int right) {
        int i = left;   // 左側の開始位置
        int j = mid;    // 右側の開始位置
        int k = left;   // tmpの書き込み位置

        list.print({}, 200);

        // 左右比較して小さい方をtmpへ格納
        while (i < mid && j < right) {
            if (list[i] <= list[j])
                tmp[k++] = list[i++];
            else
                tmp[k++] = list[j++];

            list.print({k-1}, 50);
        }

        // 左側の残りをtmpへコピー
        while (i < mid)   tmp[k++] = list[i++];
        // 右側の残りをtmpへコピー
        while (j < right) tmp[k++] = list[j++];
        // tmpのleft~rightの範囲をlistにコピー
        for (int idx=left; idx<right; idx++) {
            list[idx] = tmp[idx];
        }
    }

    void sort(List& list, List& tmp, int left, int right) {
        if (right - left <= 1) return;
        int mid = (left + right) / 2;
        sort(list, tmp, left, mid);     // 左をソート
        sort(list, tmp, mid, right);    // 右をソート
        m(list, tmp, left, mid, right); // マージ
    }

    void run() {
        List list, tmp;
        list.add({99, 98, 97, 96, 6, 21, 5, 66, 54, 55, 67, 68, 42, 1, 2, 51, 3, 4});
        const int n = list.size();
        for (int i=0; i<n; i++)
            tmp.add(0);
        sort(list, tmp, 0, n);

        list.print();
        std::cout << "Sorted" << std::endl;
    }
}
