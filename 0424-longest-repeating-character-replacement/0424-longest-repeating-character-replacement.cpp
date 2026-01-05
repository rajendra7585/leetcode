class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<int,int>m;
        int maxfreq=0;
        int left=0;
        int maxcount=0;


        int maxlen=0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            maxfreq=max(maxfreq,m[s[i]]);
            while((i-left+1)-maxfreq>k){
                m[s[left]]--;
                left++;
            }
            maxcount=max(maxcount,i-left+1);
            }
            return maxcount;
    }
};