class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        vector<vector<int>>res;
        

        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<=i;j++){
                if(j==0|| j==n-1){
                    ans[i][j]=1;
                    
                }
                else{
                    ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
                    
                }
                v.push_back(ans[i][j]);
            }
            res.push_back(v);
        }
        return res;
    }
};