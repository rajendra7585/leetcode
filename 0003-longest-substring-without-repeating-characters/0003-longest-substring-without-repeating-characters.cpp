class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int start=0;
        int maxlen=0;
        if(n==1)return 1;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end() && m[s[i]]>=start){
               
               start=m[s[i]]+1;
            }
            
            m[s[i]]=i;
            maxlen=max(maxlen,i-start+1);
        }
        return maxlen;
    }
};