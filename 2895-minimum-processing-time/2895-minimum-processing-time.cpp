class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end(),greater<int>());
        int maxi=0;
        int j=0;
        int ans=0;
        int m=t.size();
        for(int i=0;i<p.size();i++){
            int val=p[i]+t[j];
            j+=4;
            ans=max(ans,val);
        }
        return ans;
    }
};