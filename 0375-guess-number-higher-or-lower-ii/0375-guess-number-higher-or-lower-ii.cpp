class Solution {
public:
    int tabulation(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int start = n ; start >= 0; start--) {
            for (int end = 1; end <= n; end++) {
                if (start < end) {
                    int ans = INT_MAX;
                    for (int i = start; i <= end; i++) {
                        int left = (i - 1 >= start) ? dp[start][i - 1] : 0;
                        int right = (i + 1 <= end) ? dp[i + 1][end] : 0;
                        ans = min(ans, i + max(left, right));
                    }
                    dp[start][end] = ans;
                }
            }
        }

        return dp[1][n];
    }

    int getMoneyAmount(int n) { return tabulation(n); }
};
