class Solution {
public:
   int solve(int idx,int k,int n,vector<int>&presum,vector<vector<int>>&dp){
    if(k==1)return presum[n]-presum[idx];
    if(dp[idx][k]!=-1)return dp[idx][k];
    int ans=INT_MAX;
    for(int i=idx;i<=n-k;i++){
        int leftsum=presum[i+1]-presum[idx];
        int right=solve(i+1,k-1,n,presum,dp);
        int worst=max(leftsum,right);
        ans=min(ans,worst);
    }
    return dp[idx][k]=ans;
   }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>presum(n+1,0);
        for(int i=0;i<n;i++){
            presum[i+1]=presum[i]+nums[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
       return solve(0,k,n,presum,dp);
    }
};