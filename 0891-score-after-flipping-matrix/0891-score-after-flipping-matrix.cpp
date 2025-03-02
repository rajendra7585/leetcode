class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Step 1: Ensure the first column is all 1's
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];  // Flip 0 to 1 and 1 to 0
                }
            }
        }

        // Step 2: Flip columns if needed to maximize the number of 1's in each column
        for (int j = 1; j < n; j++) {  // Start from the second column as first is already handled
            int count_zeros = 0;
            int count_ones = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) count_zeros++;
                else count_ones++;
            }
            // If more zeros than ones, flip the column
            if (count_zeros > count_ones) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];  // Flip 0 to 1 and 1 to 0
                }
            }
        }

        // Step 3: Calculate the score
        int sum = 0;
        for (int i = 0; i < m; i++) {
            int row_value = 0;
            for (int j = 0; j < n; j++) {
                row_value = row_value * 2 + grid[i][j];  // Convert binary row to decimal
            }
            sum += row_value;
        }

        return sum;
    }
};
