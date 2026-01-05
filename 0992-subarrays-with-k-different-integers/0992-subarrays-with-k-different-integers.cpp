class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int len = nums.size();
        int l = 0, r = 0, cnt = 0;
        map<int, int> mmp;
        while (r < len) {
            mmp[nums[r]]++;
            while (mmp.size() > k) {
                mmp[nums[l]]--;
                if (mmp[nums[l]] == 0) {
                    mmp.erase(nums[l]);
                }
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
