class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        queue<pair<int, int>> q;

        // Step 1: Push all boundary 'O's into queue and mark them as '#'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) &&
                    board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = '#';
                }
            }
        }

        // Step 2: BFS from boundary O's
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
          auto [x,y]=q.front();
            q.pop();
            for (auto [dx,dy]: dirs) {
                int nx = x + dx, ny = y +dy;
                if (nx >= 0 && ny >= 0 && int(nx) < m && int(ny) < n &&
                    board[nx][ny] == 'O') {
                    board[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }

        // Step 3: Flip
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
