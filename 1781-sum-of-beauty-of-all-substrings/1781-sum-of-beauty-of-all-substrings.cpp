class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int leastf=INT_MAX;
                int mostf=INT_MIN;
                for(auto i:m){
                    leastf=min(i.second,leastf);
                    mostf=max(i.second,mostf);
                }
                ans+=(mostf-leastf);

            }
        }
        return ans;
    }
};