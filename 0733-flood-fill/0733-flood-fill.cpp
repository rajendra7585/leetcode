class Solution {
public:
   void solve(vector<vector<int>>& image, int sr, int sc, int color,int m,int n,int o){
    if(sr<0 ||sc<0 ||sr>=m ||sc>=n)return;
    if(image[sr][sc]!=o)return;
    image[sr][sc]=color;
    solve(image,sr+1,sc,color,m,n,o);
    solve(image,sr-1,sc,color,m,n,o);
    solve(image,sr,sc+1,color,m,n,o);
    solve(image,sr,sc-1,color,m,n,o);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int o=image[sr][sc];
        if(o==color)return image;
        solve(image,sr,sc,color,m,n,o);
        return image;
    }
};