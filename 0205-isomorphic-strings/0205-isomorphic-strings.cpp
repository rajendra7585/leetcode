class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        unordered_map<char,char>m;
        unordered_map<char,char>m2;
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end() && m2.find(t[i])==m2.end()){
                m[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else if(m.find(s[i])!=m.end() && m2.find(t[i])!=m2.end()){
                if(m[s[i]]==t[i] && m2[t[i]]==s[i]){
                    continue;
                }
                else{
                    return false;
                }
            }
            else{return false;}
        }
        return true;
    }
};