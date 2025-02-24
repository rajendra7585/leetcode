class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int>pge(n);
        vector<int>nge(n);
        vector<int>c(n);
        pge[0]=-1;
        nge[n-1]=-1;
        int maxi=a[0];
        for(int i=1;i<n;i++){
            pge[i]=maxi;
           maxi= max(maxi,a[i]);
        }
        maxi=a[n-1];
        for(int i=n-2;i>=0;i--){
            nge[i]=maxi;
            maxi=max(maxi,a[i]);
        }
        int sum=0;
        for(int i=1;i<n-1;i++){
            c[i]=min(pge[i],nge[i]);
            if(a[i]<c[i]){
                sum+=(c[i]-a[i]);
            }

        }
        return sum;

    }
};