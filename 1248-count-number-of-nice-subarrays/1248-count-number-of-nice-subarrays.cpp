class Solution {
public:
   int solve(vector<int>&nums,int k){
    int l=0;
    int n=nums.size();
    int r=0;
    int count=0;
    int oddcount=0;
    while(r<n){
        oddcount+=nums[r]%2;
        while(oddcount>k){
            if(nums[l]%2)oddcount--;
            l++;
        }
        count+=(r-l+1);
        r++;

    }
    return count;

   }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        return solve(nums,k)-solve(nums,k-1);

    }
};