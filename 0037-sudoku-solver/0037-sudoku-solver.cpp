class Solution {
    bool Col[9][9] = {0};
    bool Row[9][9] = {0};
    bool Block[9][9] = {0};

public:
    void set3Cond(int i, int j, int x, bool val = 1) {
        Row[i][x] = val;
        Col[j][x] = val;
        int bidx = (i / 3) * 3 + j / 3;
        Block[bidx][x] = val;
    }

    void setup(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char c = board[i][j];
                if (c == '.')
                    continue;

                int x = (c - '0') % 9;
                set3Cond(i, j, x);
            }
        }
    }

    void print(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j];
            cout << endl;
        }
        cout << "============\n";
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            int x = (c - '0') % 9;
                            set3Cond(i, j, x);

                            if (solve(board))
                                return 1;

                            // Backtracking
                            board[i][j] = '.';
                            set3Cond(i, j, x, 0);
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }

    bool isValid(vector<vector<char>>& board, int i, int j, char c) {
        int x = (c - '0') % 9;
        return !Row[i][x] && !Col[j][x] && !Block[(i / 3) * 3 + j / 3][x];
    }

    void solveSudoku(vector<vector<char>>& board) {
        //	print(board);
        setup(board);
        solve(board);
        //  print(board);
    }
};
