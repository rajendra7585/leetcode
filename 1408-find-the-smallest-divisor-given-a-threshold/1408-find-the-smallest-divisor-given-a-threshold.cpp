class Solution {
private:
    int get_sum(vector<int>& nums, int divisor, int threshold) {
        int i = 0, sum = 0;

        while (i < nums.size() && sum <= threshold) {
            int div = (nums[i] + divisor - 1) / divisor;
            sum += div, i++;
        }

        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = int((low + high) / 2);
            int sum = this->get_sum(nums, mid, threshold);

            if (sum > threshold) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
