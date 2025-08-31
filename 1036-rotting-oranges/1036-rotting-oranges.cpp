class Solution {
public:
    int solve(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();

        queue<pair<int, int>> rotten;
        int days = 0;
        int count = 0; // how many oranges have become rotten
        int total = 0; // total oranges (fresh + rotten)

        // count total oranges and push all initially rotten oranges into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    total++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS
        while (!rotten.empty()) {
            int sz = rotten.size();
            count += sz;

            for (int i = 0; i < sz; i++) {
                auto node = rotten.front();
                rotten.pop();
                int x = node.first;
                int y = node.second;

                for (auto d : dirs) {
                    int nx = x + d.first;
                    int ny = y + d.second;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        rotten.push({nx, ny});
                    }
                }
            }

            if (!rotten.empty())
                days++;
        }

        return (count == total) ? days : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) { return solve(grid); }
};
