class Solution {
public:
    void bfs(int src,vector<bool>&visited,vector<vector<int>>&adj){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto n:adj[u]){
                if(!visited[n]){
                    q.push(n);
                    visited[n]=true;
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( isConnected[i][j]==1){
                adj[i].push_back(j);}}

            }
        
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                bfs(i,visited,adj);
            }
        }
        return count;

    }
};