class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>arr(n,vector<int>(3));
        for(int i=0;i<n;i++){
             arr[i][0]=startTime[i];
             arr[i][1]=endTime[i];
             arr[i][2]=profit[i];
        }
        sort(arr.begin(),arr.end(),[](const auto&a,const auto&b){
               return a[1]<b[1];
        });
     vector<int>dp(n,0);
     dp[0]=arr[0][2];
     for(int i=1;i<n;i++){
        int include=arr[i][2];
        int l=0,r=i-1,idx=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid][1]<=arr[i][0]){
                 idx=mid;
                 l=mid+1;
            }
            else r=mid-1;
        }
        if(idx!=-1)include+=dp[idx];
        dp[i]=max(dp[i-1],include);
     }
      return dp[n-1];
    }
};