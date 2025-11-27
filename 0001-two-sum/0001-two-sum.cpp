class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        int i=0;
        int j=n-1;
        while(i<j){
            if(temp[i].first+temp[j].first==target)return {temp[i].second,temp[j].second};
            else if(temp[i].first+temp[j].first>target){
                j--;
            }
            else i++;
        }
        return {-1,-1};
    }
};