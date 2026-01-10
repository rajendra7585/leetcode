class Solution {
public:
   bool checkp(string &s,int i,int j){
    int n=s.size();
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
   }
    string longestPalindrome(string s) {
        int n=s.size();
        
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkp(s,i,j)){
                     string f=s.substr(i,j-i+1);
                     ans=f.size()>ans.size()?f:ans;
                }
            }
        }
        return ans;
    }
};