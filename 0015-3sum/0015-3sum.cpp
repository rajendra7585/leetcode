class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int total=nums[i]+nums[j]+nums[k];
                if(total>0)k--;
                else if(total <0)j++;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j<k && nums[j]==nums[j-1])j++;
                }

            }
        }
        return ans;
    }
};