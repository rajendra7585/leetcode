class Solution {
public:
void Reverse(vector<int>&nums, int start, int end)
{
  while (start <= end)
  {
    int temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;
    start++;
    end--;
  }
}
// Function to Rotate k elements to right

    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
  // Reverse first n-k elements
  if(k>n)k=k%n;
  Reverse(nums, 0, n - k - 1);
  // Reverse last k elements
  Reverse(nums, n - k, n - 1);
  // Reverse whole array
  Reverse(nums, 0, n - 1);
}
};