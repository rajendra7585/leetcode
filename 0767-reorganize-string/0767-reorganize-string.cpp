class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>f;
        int n=s.length();
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        char prev='#';
        string ans="";
        for(int k=0;k<n;k++){
            char best=0;
            int bc=-1;
            for(const auto i:f){
                if(i.second>0 && i.first!=prev){
                    if(i.second>bc){
                        best=i.first;
                        bc=i.second;
                    }
                }
            }
            if(bc==-1)return "";
            ans.push_back(best);
            f[best]--;
            prev=best;
        }
        return ans;
    }
};