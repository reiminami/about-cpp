#pragma once
#include "Grid.hpp"

namespace bestFirstSearch {
    struct Node {
        int x, y;
        int cost;

        bool operator<(const Node& other) const {
            return cost > other.cost;
        };
    };

    int heuristic(int x, int y, const std::pair<int, int>& goal) {
        return abs(x - goal.first) + abs(y - goal.second);
    }

    void run() {
        Grid grid;

        std::priority_queue<Node> pq;
        std::vector<std::vector<bool>> visited(grid.height, std::vector<bool>(grid.width, false));
        int sx = grid.start.first;
        int sy = grid.start.second;

        pq.push({sx, sy, heuristic(sx, sy, grid.goal)});
        visited[sx][sy] = true;

        while (!pq.empty()) {
            Node node = pq.top();
            pq.pop();
            int x = node.x;
            int y = node.y;

            grid.print("評価軸: " + std::to_string(node.cost));
            if (grid.cells[x][y] != 'S' && grid.cells[x][y] != 'G')
                grid.cells[x][y] = '0';
            if (x == grid.goal.first & y == grid.goal.second) {
                std::cout << "Goal" << std::endl;
                return;
            }

            for (int i=0; i<4; i++) {
                int nx = x + grid.dx[i];
                int ny = y + grid.dy[i];
                if (nx < 0 || ny < 0 || nx >= grid.height || ny >= grid.width) continue;
                if (grid.cells[nx][ny] == '#')  continue;
                if (visited[nx][ny])            continue;
                visited[nx][ny] = true;
                int cost = heuristic(nx, ny, grid.goal);
                pq.push({nx, ny, cost});
            }
        }
        std::cout << "失敗" << std::endl;
    }
}
