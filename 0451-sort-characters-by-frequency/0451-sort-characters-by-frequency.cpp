class Solution {
public:

   static bool cmp(const pair<char,int>& a,const pair<char,int>& b){
       return a.second>b.second;
   }
    string frequencySort(string s) {
        int n=s.size();
        string ans="";
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
             m[s[i]]++;  
        }
        vector<pair<char,int>>res(m.begin(),m.end());
        sort(res.begin(),res.end(),cmp);
        for(const auto &it:res){
              int k=it.second;
              while(k--){
                   ans+=it.first;
              }
        }

        return ans;

    }
};