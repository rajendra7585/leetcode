class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        int sum=0;
        int maxsum=INT_MIN;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
           maxi=max(maxi,nums[i]);
        }
        if(maxi<=0)return maxi;
        else{
        for(int i=0;i<n;i++){
            if(s.find(nums[i])!=s.end()){
                continue;
                
            }
            else if(nums[i]<0)continue;
            
            
            else{
                if(sum<0)sum=0;
                sum+=nums[i];
                maxsum=max(sum,maxsum);
                s.insert(nums[i]);
            }
            
        }
        return maxsum;}
    }
};