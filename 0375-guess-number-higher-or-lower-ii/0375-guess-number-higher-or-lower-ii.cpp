class Solution {
public:
    int memoization(int start, int end, vector<vector<int>>& dp) {
        if (start >= end)
            return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans,
                      i + max(memoization(start, i - 1,dp), memoization(i + 1, end,dp)));
        }
        return dp[start][end]=ans;
    }
    int recursion(int start, int end) {
        if (start >= end)
            return 0;
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans,
                      i + max(recursion(start, i - 1), recursion(i + 1, end)));
        }
        return ans;
    }
    int getMoneyAmount(int n) {
        // return recursion(1,n);
        vector<vector<int>> dp(
            n + 1, vector<int>(n + 1, -1));
             return memoization(1, n, dp);
    }
};