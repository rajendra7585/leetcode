class Solution {
public:
    vector<int> getRow(int n) {
        n=n+1;
        vector<vector<int>>ans(n,vector<int>(n,0));
        vector<int>res(n);
        

        for(int i=0;i<n;i++){
            
            for(int j=0;j<=i;j++){
                if(j==0|| j==n-1){
                    ans[i][j]=1;
                    
                }
                else{
                    ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
                    
                }
               
            }
            
            
        }
        
            res=ans[n-1];

        return res;
    }
};