class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)q.push({i,j});
                else mat[i][j]=INT_MAX;
            }
        }
        vector<pair<int,int>>dt={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto p:dt){
                int mx=x+p.first;
                int my=y+p.second;
                if(mx>=0 && my>=0 && mx<m && my<n && mat[mx][my]>mat[x][y]+1){
                    mat[mx][my]=mat[x][y]+1;
                    q.push({mx,my});
                }
            }

        }
        return mat;
    }
};