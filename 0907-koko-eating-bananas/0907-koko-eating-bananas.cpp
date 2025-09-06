class Solution {
public:
   long long solve(vector<int>& piles, int mid){
    long long totalh=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        totalh+=(piles[i]+mid-1)/mid;
    }
    return totalh;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long totalh=solve(piles,mid);
            if(totalh<=h){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};