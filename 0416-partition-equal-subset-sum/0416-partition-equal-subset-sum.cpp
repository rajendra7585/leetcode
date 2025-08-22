class Solution {
public:
    int memoization(vector<int>& nums, int n, int s, int i,vector<vector<int>>&dp) {
        if (s < 0)
            return 0;
        if (i >= n)
            return 0;
        if (s == 0)
            return 1;
        if(dp[i][s]!=-1)return dp[i][s];
        int include = 0;
        if (nums[i] <= s) {
            include = memoization(nums, n, s - nums[i], i + 1,dp);
        }
        int exclude = memoization(nums, n, s, i + 1,dp);
        return dp[i][s]=(include||exclude);
    }
// }  int srecursion(vector<int>& nums, int n, int s, int i) {
//     if (s < 0)
//         return 0;
//     if (i >= n)
//         return 0;
//     if (s ==
//         return 1;
//     int include = 0;
//     if (nums[i] <= s) {
//         include = srecursion(nums, n, s - nums[i], i + 1);
    // }
//     int exclude = srecursion(nums, n, s, i + 1);
//     return include || exclude;
// }
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    if (sum & 1)
        return 0;
    int s = sum / 2;
    int i = 0;
    // return srecursion(nums,n,s,i);
    vector<vector<int>> dp(n + 1, vector<int>(s+1, -1));
    return memoization(nums,n, s, i, dp);
}
};