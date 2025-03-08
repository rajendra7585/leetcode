class Solution {
public:
    int minimumRecolors(string b, int k) {
        int n=b.length();
        int w=0;
        for(int i=0;i<k;i++){
            if(b[i]=='W')w++;
        }
        int ans=w;
        for(int i=k;i<n;i++){
            if(b[i]=='W')w++;
            if(b[i-k]=='W')w--;
            ans=min(ans,w);
        }
        return ans;
    }
};