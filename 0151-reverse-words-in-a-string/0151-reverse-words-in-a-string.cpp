class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        string r = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i]!= ' ') {
                r = s[i] + r;
            } else {
               if(r!=""){
                if (ans == "") {
                    ans = r;
                } else {
                    ans=ans+" "+r;
                }
                r = "";
            }}
        }
        if(r!=""){
        if (ans == "") {
            ans = r;
        } else {
            ans=ans+" "+r;
        }}
        return ans;
    }

}
;