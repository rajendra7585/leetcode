class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int last=0;
        int curr=0;
        int jumps=0;
        if(n<=1)return jumps;
        for(int i=0;i<n;i++){
            last=max(last,i+nums[i]);
            if(curr==i){
                jumps++;
                curr=last;
            }
            if(curr>=n-1)break;
        }
        return jumps;
    }
};