class Solution {
public:
int tabl(int n,vector<int>& coins,int amount){
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for(int c:coins){
            if(i>=c && dp[i-c]!=INT_MAX){
            dp[i]=min(dp[i],1+dp[i-c]);}
        }
    }
    return dp[amount];
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
