#pragma once
#include "Grid.hpp"

namespace dfs {
    void run() {
        Grid grid;
        std::stack<std::pair<int, int>> s;
        std::vector<std::vector<int>> visited(grid.height, std::vector<int>(grid.width, -1));
        visited[grid.start.first][grid.start.second] = 0;
        s.push(grid.start);

        while (!s.empty()) {
            auto v = s.top();
            s.pop();
            int x = v.first;
            int y = v.second;

            // 描画用
            std::string txt = std::to_string(visited[x][y]);
            grid.print(txt + "歩の位置を探索中");
            if (grid.cells[x][y] != 'S' && grid.cells[x][y] != 'G') grid.cells[x][y] = '0';

            if (grid.cells[x][y] == 'G') break;

            for (int i=0; i<4; i++) {
                int nx = x + grid.dx[i];
                int ny = y + grid.dy[i];
                if (nx < 0 || ny < 0 || nx >= grid.height || ny >= grid.width) continue;
                if (grid.cells[nx][ny] == '#')  continue;
                if (visited[nx][ny] != -1)      continue;
                visited[nx][ny] = visited[x][y] + 1;
                s.push({nx, ny});
            }
        }
        std::cout << "距離: " << visited[grid.goal.first][grid.goal.second] << std::endl;
    }
}
