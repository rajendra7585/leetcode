class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans(2);
        int n=nums.size();
        ans[0]=-1;
        ans[1]=-1;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int k=target-nums[i];
            if(m.find(k)!=m.end()){
                ans[0]=(m[k]);
                ans[1]=(i);
                break;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};