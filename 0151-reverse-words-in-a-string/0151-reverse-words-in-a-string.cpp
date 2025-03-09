class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        vector<string>ans;
        string str;
        string res;
        for(int i=0;i<n;i++){
            if (s[i] == ' ') {
                if (!str.empty()) {
                    ans.push_back(str);  // Push the non-empty word
                    str = "";
                }
            }
            else if(i==n-1){
                str+=s[i];
                ans.push_back(str);
            }
            else{
                str+=s[i];

            }
        }
        for(int i=ans.size()-1;i>=0;i--){
            
            res+=ans[i];            if(i>0){
            res+=" ";}

        }
        return res;

        
    }
};