#define MOD 1000000007
class Solution {
public:
    long long int recurs(int n, int k, int target, vector<vector<long long int>>& dp) {
        if (n < 0)
            return 0;
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 && target != 0)
            return 0;
        if (n != 0 && target == 0)
            return 0;
        if(dp[n][target]!=-1)return dp[n][target];
        long long int ans = 0;
        for (int i = 1; i <= k; i++) {
            long long int rans=0;
            if(target-i>=0){
                rans=recurs(n-1,k,target-i,dp);
            }
            ans =(ans % MOD + rans%MOD)%MOD;
        }
        return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
        return recurs(n,k,target,dp);
    }
};