#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

struct List {
    std::vector<int> data;
    void add(int value) {
        if (value > 99) {
            std::cout << "Number limit: 99" << std::endl;
            exit(1);
        }
        data.push_back(value);
    }

    void add(std::vector<int> values) {
        for (int value : values) {
            this->add(value);
        }
    }

    int size() const {
        return data.size();
    }

    int& operator[](int index) {
        return data[index];
    }

    void print(const std::vector<int>& highlight = {}, int sleepMs = 200) const {
        system("clear");

        for (int idx=0; idx<data.size(); idx++) {
            const auto& v = data[idx];
            bool marked = false;
            for (int h : highlight) {
                if (h == idx) {
                    marked = true;
                    break;
                }
            }

            std::cout << (marked ? "> " : "  ") << std::left << std::setw(4) << v;
            for (int i=0; i<v; i++) std::cout << "■";
            std::cout << std::endl;
        }

        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepMs));
    }
};
