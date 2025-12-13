class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        int answer=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(const auto i:m){
            int k=(i.second)-1;
            answer+=(k*(k+1)/2);
        }
        return answer;
    }
};