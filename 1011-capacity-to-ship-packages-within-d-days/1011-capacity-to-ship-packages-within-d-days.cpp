class Solution {
public:
   int solve(vector<int>&w,int mid){
    int n=w.size();
    int sum=0;
    int days=1;
    for(int i=0;i<n;i++){
        if((sum+w[i])>mid){
            sum=w[i];
            days++;

        }
        else{
            sum+=w[i];
        }
    }
    return days;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int ans;
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int req=solve(weights,mid);
            if(req<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};