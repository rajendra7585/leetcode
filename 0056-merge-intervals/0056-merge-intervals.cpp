class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](const auto &a,const auto &b){
            return a[0]<b[0];
        });
        int n=a.size();
        vector<vector<int> > ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++){
            vector<int>curr=a[i];
            if(curr[0]<=ans[ans.size()-1][1]){
        ans[ans.size()-1][0]=min(ans[ans.size()-1][0],curr[0]);
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],curr[1]);

            }
            else{
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};