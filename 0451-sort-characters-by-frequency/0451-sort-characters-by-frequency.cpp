class Solution {
public:
   static bool compareByValue(const pair<char, int>& a, const pair<char,int>& b) {
    return a.second > b.second;  // Sorting by the string value
}
    string frequencySort(string s) {
        int n=s.length();
        string ans;
        map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        vector<pair<char,int>>v(m.begin(),m.end());
        sort(v.begin(),v.end(),compareByValue);
        for (const auto& pair : v){
            int k=pair.second;
            while(k--){
               ans+=pair.first;
            }
        }
      return ans;

    }
};