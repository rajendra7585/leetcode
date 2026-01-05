class Solution {
public:
    int rajendra(vector<int>& nums, int k) {
        int len = nums.size(), r = 0, l = 0, sum = 0, count = 0;
        int countOdd=0;
        while (r < len) {
            countOdd += nums[r] % 2;
            while (countOdd > k) {
                if (nums[l] % 2 != 0)
                    countOdd--;
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

  int numberOfSubarrays(vector<int>& nums, int k) {
    int n=nums.size();
    return rajendra(nums,k)-rajendra(nums,k-1);
}
}
;