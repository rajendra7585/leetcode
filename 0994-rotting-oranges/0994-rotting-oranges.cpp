class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        int time=0;
        vector<pair<int,int>>dire={{1,0},{-1,0},{0,1},{0,-1}};
        while(fresh>0 && !q.empty()){
            
            time++;
            int s=q.size();
            while(s--){
                const auto node=q.front();
                q.pop();
                int x=node.first;
                int y=node.second;
                for(auto i:dire){
                    int dx=x+i.first;
                    int dy=y+i.second;
                    if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]==1){
                        grid[dx][dy]=2;
                        fresh--;
                        q.push({dx,dy});
                    }
                }

            }
        }
        if(fresh>0)return -1;
        else return time;
    }
};