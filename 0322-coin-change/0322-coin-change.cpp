class Solution {
public:
int tabl(int n,vector<int>& coins,int amount){
    vector<vector<int>>dp(n,vector<int>(amount+1,INT_MAX));
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int t=1;t<=amount;t++){
        if(t%coins[0]==0)dp[0][t]= t/coins[0];
        
    }
    for(int i=1;i<n;i++){
        for(int t=1;t<=amount;t++){
            int include=INT_MAX;
            if(t>=coins[i]){
                if(dp[i][t-coins[i]]!=INT_MAX)include=1+dp[i][t-coins[i]];
            }
            int exclude=dp[i-1][t];
            dp[i][t]=min(include,exclude);
        }
        
    }
    return dp[n-1][amount];

}
    int recurs(vector<int>& coins, int idx, int amount,vector<vector<int>>&dp) {
        if (amount == 0)
            return 0;
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return INT_MAX;
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        
        int include = INT_MAX;
        if (amount >= coins[idx]){
            int sub=recurs(coins, idx , amount - coins[idx],dp);
            if(sub!=INT_MAX){
                include=1+sub;
            }}
            int exclude = recurs(coins, idx - 1, amount,dp);
        return dp[idx][amount]=min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = tabl(n,coins,amount);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
