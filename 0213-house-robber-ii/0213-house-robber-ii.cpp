class Solution {
public:
   int solve(vector<int>&a){
    int n=a.size();
    if(n==0)return 0;
    if(n==1)return a[0];
    long long int prev=a[0];
    long long int prev2=0;
    for(int i=1;i<n;i++){
        long long int include=a[i];
        if(i>1)include+=prev2;
        long long int exclude=prev;
        long long int curr=max(include,exclude);
        prev2=prev;
        prev=curr;

    }
    return prev;

   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int>arr1,arr2;
        for(int i=0;i<n;i++){
            if(i!=0)arr1.push_back(nums[i]);
            if(i!=n-1)arr2.push_back(nums[i]);
        }
        return max(solve(arr1),solve(arr2));
    }
};