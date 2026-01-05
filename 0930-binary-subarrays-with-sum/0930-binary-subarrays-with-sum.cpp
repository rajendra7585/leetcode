class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int sum=0;
        int count=0;
        
        unordered_map<int,int>m;
        m[0]++;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-goal;
            if(m.find(rem)!=m.end()){
                count+=m[rem];
            }
            m[sum]++;
        }
        return count;
   }
};