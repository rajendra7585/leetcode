class Solution {

    

public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int m = s.size();
        int j = m - 1;
        
        for (auto k : s) {
            nums[j]=k;
            j--;
        }
        sort(nums.begin(),nums.begin()+m);
        
        return m;
    }
};