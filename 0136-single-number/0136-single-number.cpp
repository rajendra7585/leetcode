class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xoor=0;
        for(int i=0;i<n;i++){
            xoor=xoor^nums[i];
        }
        return xoor;
    }
};