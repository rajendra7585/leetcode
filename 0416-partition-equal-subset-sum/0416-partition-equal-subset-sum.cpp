class Solution {
public:
   
    bool recurs(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(i>=n)return 0;
        if(target<0)return 0;
        if(target==0)return 1;
        if(dp[i][target]!=-1)return dp[i][target];
        bool include=recurs(i+1,target-nums[i],nums,dp);
        bool exclude=recurs(i+1,target,nums,dp);
        return dp[i][target]=(include||exclude);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum&1)return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        bool ans=recurs(0,target,nums,dp);
        return ans;
    }
};