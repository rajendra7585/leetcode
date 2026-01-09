class Solution {
public:
   int getsum(vector<int>&nums,int mid){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        int t=((nums[i]+mid-1)/mid);
        sum+=t;

    }
    return sum;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int ans;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=int((low+high)/2);
            int sum=getsum(nums,mid);
            if(sum>threshold){
                
                low=mid+1;
            
            }
            else{
                ans=mid;
                high=mid-1;
                
            }
        }
        return low;
    }
};