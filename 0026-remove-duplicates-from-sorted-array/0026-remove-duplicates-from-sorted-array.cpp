class Solution {

    

public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int m = s.size();
        int j = m - 1;
        vector<int>d;
        for (auto k : s) {
            d.push_back(k);
            j--;
        }
        sort(d.begin(),d.end());
        for(int i=0;i<m;i++){
            nums[i]=d[i];
        }
        return m;
    }
};