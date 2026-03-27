#pragma once
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

struct Grid {
    std::vector<std::string> cells = {
        "##########",
        "#S...#...#",
        "#.##.#.#G#",
        "#......#.#",
        "#....#.#.#",
        "#........#",
        "##########"
    };
    int height = cells.size();
    int width  = cells[0].size();
    int dx[4]  = {1, -1, 0, 0};
    int dy[4]  = {0, 0, 1, -1};
    std::pair<int, int> start, goal;

    Grid() {
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                if (cells[i][j] == 'S') start = {i, j};
                if (cells[i][j] == 'G') goal  = {i, j};
            }
        }
    }

    void print(std::string txt = "") {
        system("clear");
        for (auto& cell : cells) std::cout << cell << std::endl;
        std::cout << std::endl << txt << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
};
